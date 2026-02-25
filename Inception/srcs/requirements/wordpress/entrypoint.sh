#!/bin/bash
set -e

# Wait for MariaDB to be ready //remove sleep subject states that the sleep can not be infinity.
while ! nc -z mariadb 3306; do
    sleep 1
done

# Create wp-config.php if not exists
if [ ! -f /var/www/wordpress/wp-config.php ]; then
    cp /var/www/wordpress/wp-config-sample.php /var/www/wordpress/wp-config.php
    
    sed -i "s/database_name_here/$(cat /run/secrets/db_password)/g" wp-config.php
    sed -i "s/username_here/$MYSQL_USER/g" wp-config.php
    sed -i "s/password_here/$(cat /run/secrets/db_password)/g" wp-config.php
    sed -i "s/localhost/mariadb/g" wp-config.php
fi

# Run WordPress CLI to set up admin user if DB is empty
wp core install \
    --url="https://$DOMAIN_NAME" \
    --title="$WP_TITLE" \
    --admin_user="$WP_ADMIN_USER" \
    --admin_password="$(cat /run/secrets/wp_admin_password)" \
    --admin_email="$WP_ADMIN_EMAIL" \
    --allow-root 2>/dev/null || true

# Start PHP-FM in foreground
php-fpm8.2 -F