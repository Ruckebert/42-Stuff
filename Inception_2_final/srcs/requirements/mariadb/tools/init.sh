#!/bin/bash
set -e

# MariaDB needs this directory for its socket file - it doesn't exist by default
mkdir -p /run/mysqld
chown mysql:mysql /run/mysqld

# First boot: initialize system tables
if [ ! -d "/var/lib/mysql/mysql" ]; then
    echo "Initializing MariaDB database..."
    mysql_install_db --user=mysql --datadir=/var/lib/mysql --skip-test-db
fi

# First boot: create our application database and users
if [ ! -d "/var/lib/mysql/${MYSQL_DB}" ]; then
    echo "Creating database, users and permissions..."

    cat > /tmp/init.sql <<EOF
CREATE DATABASE IF NOT EXISTS \`${MYSQL_DB}\`;
CREATE USER IF NOT EXISTS '${MYSQL_USER}'@'%' IDENTIFIED BY '$(cat /run/secrets/db_password)';
GRANT ALL PRIVILEGES ON \`${MYSQL_DB}\`.* TO '${MYSQL_USER}'@'%';
ALTER USER 'root'@'localhost' IDENTIFIED BY '$(cat /run/secrets/db_root_password)';
FLUSH PRIVILEGES;
EOF

    exec mysqld --user=mysql --datadir=/var/lib/mysql --init-file=/tmp/init.sql
else
    echo "Database already exists, starting normally..."
    exec mysqld --user=mysql --datadir=/var/lib/mysql
fi