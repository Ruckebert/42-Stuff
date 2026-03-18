# Inception — Developer Documentation
*42 School Project · aruckenb*

---

## 1. Environment Setup from Scratch

Follow every step in order before running any `make` command.

### 1.1 Prerequisites
- Docker Engine v20+ and the Docker Compose plugin
- Git to clone the repository
- `sudo` access — required for `/etc/hosts` edits and creating data directories
- Ubuntu or any Debian-based Linux host

### 1.2 Project Directory Layout

```
Inception/
├── Makefile
├── secrets/                  ← sensitive credentials (never commit!)
│   ├── db_password.txt
│   ├── db_root_password.txt
│   ├── wp_admin_password.txt
│   └── wp_editor_password.txt
└── srcs/
    ├── .env                  ← non-sensitive env config
    ├── docker-compose.yml
    └── requirements/
        ├── nginx/
        ├── wordpress/
        └── mariadb/
```

### 1.3 Populate Secrets

Create all four secret files. These are mounted read-only at `/run/secrets/` inside containers.

```bash
mkdir -p Inception/secrets

echo 'your_root_pw'     > Inception/secrets/db_root_password.txt
echo 'your_db_pw'       > Inception/secrets/db_password.txt
echo 'your_admin_pw'    > Inception/secrets/wp_admin_password.txt
echo 'your_editor_pw'   > Inception/secrets/wp_editor_password.txt
```

> *** Never commit the `secrets/` directory to Git.** Ensure it is listed in `.gitignore`.

### 1.4 Review `srcs/.env`

This file holds non-sensitive configuration passed to the `wordpress` and `mariadb` containers:

```env
DOMAIN_NAME=aruckenb.42.fr

MYSQL_DB=wordpress_db
MYSQL_USER=wp_user

WORDPRESS_DB_NAME=wordpress_db
WORDPRESS_DB_USER=wp_user
WORDPRESS_TABLE_PREFIX=wp_

WORDPRESS_ADMIN_USER=aruckenb_owner
WORDPRESS_ADMIN_EMAIL=aruckenb@student.42.fr
WP_TITLE=aruckenb
```

### 1.5 Add Local DNS Entry

The domain must resolve to localhost for browser access:

```bash
echo '127.0.0.1  aruckenb.42.fr' | sudo tee -a /etc/hosts
```

---

## 2. Building & Launching the Project

All operations are driven by the Makefile at the project root.

| Command | Description |
|---|---|
| `make` | Build images, create data dirs, start all services (default) |
| `make build` | Build or rebuild Docker images without starting |
| `make up` | Create `~/data` dirs and start services in detached mode |
| `make down` | Stop and remove containers (data and volumes preserved) |
| `make re` | `make down` followed by `make up` |
| `make logs` | Tail stdout/stderr from all running containers |
| `make clean` | Stop containers and prune dangling images and networks |
| `make fclean` | Full cleanup: containers, volumes, images, and `~/data` |
| `make ps` | List running containers (alias for `docker ps`) |

> ** `make fclean` permanently deletes all WordPress and MariaDB data stored in `~/data`.** Use `make down` to safely stop services while preserving data.

---

## 3. Managing Containers & Volumes

### 3.1 Shell Access & Logs

```bash
# Open a shell in any running container
docker exec -it wordpress bash
docker exec -it mariadb bash
docker exec -it nginx bash

# Stream logs (all services)
docker compose -f srcs/docker-compose.yml logs -f

# Stream logs (single service)
docker compose -f srcs/docker-compose.yml logs -f wordpress

# Inspect container environment variables
docker inspect wordpress
```

### 3.2 Volume Locations on Host

| Volume | Host Path | Container Mount |
|---|---|---|
| `wordpress` | `~/data/wordpress` | `/var/www/wordpress` |
| `mariadb` | `~/data/mariadb` | `/var/lib/mysql` |

```bash
# Inspect data directly on the host
ls ~/data/wordpress    # WordPress files, themes, plugins
ls ~/data/mariadb      # MariaDB raw InnoDB data files
```

---

## 4. Database Access — SQL Reference

### 4.1 Connect to MariaDB

```bash
# As the WordPress application user
docker compose -f srcs/docker-compose.yml exec mariadb \
  mysql -u wp_user -p wordpress_db

# As root (enter db_root_password when prompted)
docker compose -f srcs/docker-compose.yml exec mariadb \
  mysql -u root -p
```

### 4.2 Useful Queries

```sql
SHOW DATABASES;
USE wordpress_db;
SHOW TABLES;

-- Users
SELECT ID, user_login, user_email FROM wp_users;

-- Published posts
SELECT ID, post_title FROM wp_posts WHERE post_status = 'publish';

-- Comments
SELECT comment_ID, comment_author, comment_content FROM wp_comments;

-- Site settings (first 20 rows)
SELECT option_name, option_value FROM wp_options LIMIT 20;

EXIT;
```

---

## 5. Networking

### 5.1 Exposed & Internal Ports

| Service | Port | Notes |
|---|---|---|
| `nginx` | 443 — HTTPS | Only externally exposed port |
| `nginx` (redirect) | 80 — HTTP | Redirects to HTTPS; not exposed to host |
| `wordpress` | 9000 (internal) | PHP-FPM; accessible only from nginx |
| `mariadb` | 3306 (internal) | Accessible only from wordpress |

> ** Verify port 80 is blocked from outside:** `curl -v http://aruckenb.42.fr` should fail or receive a connection refused.

### 5.2 `inception` Bridge Network

All services share the `inception` Docker bridge network. Containers address each other by service name (e.g. `mariadb:3306`, `wordpress:9000`).

```bash
# Inspect the network
docker network inspect srcs_inception

# Test connectivity from wordpress to mariadb
docker exec -it wordpress nc -zv mariadb 3306
```

---

## 6. SSL / TLS Configuration

NGINX uses a self-signed certificate generated at image build time. Certificate files live inside the nginx container:

- `/etc/nginx/ssl/certificate.crt` — public certificate
- `/etc/nginx/ssl/private.key` — private key

Only **TLSv1.2** and **TLSv1.3** are permitted. 