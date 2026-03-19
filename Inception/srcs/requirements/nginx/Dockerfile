FROM debian:bookworm-slim

RUN apt-get update && apt-get install -y \
    nginx \
    openssl \
    && rm -rf /var/lib/apt/lists/*

COPY tools/gen_tls.sh /usr/local/bin/gen_tls.sh
RUN chmod +x /usr/local/bin/gen_tls.sh && \
    /usr/local/bin/gen_tls.sh && \
    rm -f /etc/nginx/sites-enabled/default /etc/nginx/sites-available/default 2>/dev/null || true

## COPY conf/nginx.conf /etc/nginx/nginx.conf
COPY conf/default.conf /etc/nginx/conf.d/default.conf

RUN ln -sf /dev/stdout /var/log/nginx/access.log && \
    ln -sf /dev/stderr /var/log/nginx/error.log

EXPOSE 443

ENTRYPOINT ["nginx", "-g", "daemon off;"]
