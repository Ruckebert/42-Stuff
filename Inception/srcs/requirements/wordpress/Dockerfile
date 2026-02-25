FROM debian:bookworm-slim

RUN apt-get update && apt-get install -y \
    php-fpm \
    php-mysql \
    php-curl \
    php-gd \
    php-mbstring \
    php-xml \
    wget \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /var/www/wordpress

RUN wget https://wordpress.org/latest.tar.gz && \
    tar -xzf latest.tar.gz && \
    mv wordpress/* . && \
    rm -rf latest.tar.gz wordpress

COPY tools/entrypoint.sh /
RUN chmod +x /entrypoint.sh

COPY conf/www.conf /etc/php/8.2/fpm/pool.d/www.conf

EXPOSE 9000

ENTRYPOINT ["/entrypoint.sh"]