#!/bin/bash
set -e

# Check if database is already initialized
if [ ! -d "/var/lib/mysql/mysql" ]; then
    echo "Initializing MariaDB..."

    mysql_install_db --user=mysql --datadir=/var/lib/mysql

    echo "Starting MariaDB for initial setup..."
    mysqld_safe &
    MARIADB_PID=$!

    # Wait for MariaDB to be ready
    echo "Waiting for MariaDB to be ready..."
    for i in {1..30}; do
        if mysql -u root -e "SELECT 1" &>/dev/null; then
            echo "MariaDB is ready!"
            break
        fi
        echo "Waiting... ($i/30)"
        sleep 1
    done

    echo "Setting up database and users..."
    mysql -u root <<EOF
ALTER USER 'root'@'localhost' IDENTIFIED BY '$(cat /run/secrets/db_root_password)';
FLUSH PRIVILEGES;
CREATE DATABASE IF NOT EXISTS \`${MYSQL_DB}\`;
CREATE USER IF NOT EXISTS '${MYSQL_USER}'@'%' IDENTIFIED BY '$(cat /run/secrets/db_password)';
GRANT ALL PRIVILEGES ON \`${MYSQL_DB}\`.* TO '${MYSQL_USER}'@'%';
FLUSH PRIVILEGES;
EOF

    kill $MARIADB_PID 2>/dev/null || true
    wait $MARIADB_PID 2>/dev/null || true

    echo "MariaDB setup complete"
fi

echo "Starting MariaDB..."
exec mysqld_safe
