FROM debian:bookworm-slim

RUN apt-get update && apt-get install -y \
    php-fpm \
    php-mysql \
    php-curl \
    php-gd \
    php-mbstring \
    php-xml \
    wget \
    curl \
    netcat-openbsd \
    default-mysql-client \  
    && rm -rf /var/lib/apt/lists/*

RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
    chmod +x wp-cli.phar && \
    mv wp-cli.phar /usr/local/bin/wp

WORKDIR /var/www/wordpress

RUN wget -qO- https://wordpress.org/latest.tar.gz | tar -xz --strip-components=1 \
    && chown -R www-data:www-data /var/www/wordpress

COPY tools/entrypoint.sh /
RUN chmod +x /entrypoint.sh

COPY conf/www.conf /etc/php/8.2/fpm/pool.d/www.conf

EXPOSE 9000

ENTRYPOINT ["/entrypoint.sh"]
