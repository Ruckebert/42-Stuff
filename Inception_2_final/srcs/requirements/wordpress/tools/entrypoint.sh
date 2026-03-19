#!/bin/bash
set -e

counter=0
while ! nc -z mariadb 3306; do
    echo "Waiting for MariaDB port... ($counter)"
    sleep 2
    counter=$((counter + 1))
    if [ $counter -eq 30 ]; then
        echo "ERROR: MariaDB port never opened — exiting so Docker can restart us."
        exit 1
    fi
done

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

echo "Waiting for MariaDB to accept connections..."
connected=0
for i in $(seq 1 30); do
    if mysql -h mariadb -u "${WORDPRESS_DB_USER}" -p"$(cat /run/secrets/db_password)" "${WORDPRESS_DB_NAME}" -e "SELECT 1;" &>/dev/null; then
        echo "Database connection OK."
        connected=1
        break
    fi
    echo "DB not ready yet... ($i/30)"
    sleep 3
done

if [ $connected -eq 0 ]; then
    echo "ERROR: Could not connect to database — exiting so Docker can restart us."
    exit 1
fi

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
        --allow-root" || echo "Editor user already exists — skipping."

    echo "WordPress setup complete."
else
    echo "WordPress already installed — skipping setup."
fi

echo "Starting PHP-FPM..."
exec php-fpm8.2 -F