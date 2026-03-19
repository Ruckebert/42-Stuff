#!/bin/bash
set -e

CERT_DIR="/etc/nginx/ssl"
CERT="$CERT_DIR/certificate.crt"
KEY="$CERT_DIR/private.key"

mkdir -p "$CERT_DIR"

echo "Generating new TLS certificate and private key..."

openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
    -keyout "$KEY" \
    -out "$CERT" \
    -subj "/C=FR/ST=IDF/L=Paris/O=42/CN=aruckenb.42.fr"

chmod 600 "$KEY"
chmod 644 "$CERT"

echo "TLS certificate generated:"
echo "  Certificate : $CERT"
echo "  Private key : $KEY"
echo "  Validity    : $(openssl x509 -noout -dates -in "$CERT" | grep 'notAfter' | cut -d= -f2)"