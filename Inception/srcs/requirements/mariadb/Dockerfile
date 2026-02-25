FROM debian:bookworm-slim

RUN apt-get update && apt-get install -y \
    mariadb-server \
    && rm -rf /var/lib/apt/lists/*

COPY tools/init.sh /
RUN chmod +x /init.sh

COPY conf/my.cnf /etc/mysql/my.cnf

EXPOSE 3306

CMD ["/init.sh"]