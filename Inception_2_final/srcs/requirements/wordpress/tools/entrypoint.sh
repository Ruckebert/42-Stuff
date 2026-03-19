#!/bin/bash
set -e

# Wait for MariaDB to be ready
counter=0
while ! nc -z mariadb 3306 && [ $counter -lt 30 ]; do
    echo "Waiting for MariaDB..."
    sleep 1
    counter=$((counter + 1))
done

if [ $counter -eq 30 ]; then
    echo "ERROR: MariaDB failed to start!"
    exit 1
fi

# create wp-config.php if missing
if [ ! -f /var/www/wordpress/wp-config.php ]; then
    echo "Creating wp-config.php..."
    wp config create \
        --dbname=${WORDPRESS_DB_NAME} \
        --dbuser=${WORDPRESS_DB_USER} \
        --dbpass=$(cat /run/secrets/db_password) \
        --dbhost=mariadb \
        --allow-root
    chown www-data:www-data /var/www/wordpress/wp-config.php
fi

# install WordPress if DB tables are missing
if ! wp core is-installed --allow-root 2>/dev/null; then
    echo "Installing WordPress..."
    su - www-data -s /bin/bash -c "cd /var/www/wordpress && wp core install \
        --url=https://${DOMAIN_NAME} \
        --title='${WP_TITLE}' \
        --admin_user='${WORDPRESS_ADMIN_USER}' \
        --admin_password='$(cat /run/secrets/wp_admin_password)' \
        --admin_email='${WORDPRESS_ADMIN_EMAIL}' \
        --allow-root"

    echo "Creating editor user..."
    su - www-data -s /bin/bash -c "cd /var/www/wordpress && wp user create editor editor@example.com \
        --role=editor \
        --user_pass='$(cat /run/secrets/wp_editor_password)' \
        --allow-root" || echo "User already exists"
fi

echo "Starting PHP-FPM..."
exec php-fpm8.2 -F