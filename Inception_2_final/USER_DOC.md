# Inception — User Guide
*42 School Project · aruckenb*

---

## 1. What Inception Provides

Inception runs three containerised services that work together to host a fully functional WordPress website, served securely over HTTPS.

| Service | Technology | Role |
|---|---|---|
| Web Server | NGINX | Handles HTTPS on port 443; terminates TLS; proxies PHP requests to WordPress |
| Application | WordPress + PHP-FPM | Runs the CMS; processes PHP; reads/writes to the database |
| Database | MariaDB | Stores all WordPress data: posts, users, comments, settings |

**Request flow:**
```
Browser (HTTPS)  →  NGINX : 443  →  PHP-FPM : 9000  →  WordPress  →  MariaDB : 3306
```

---

## 2. Starting and Stopping the Stack

### Starting the project

Run the following from the project root (where the Makefile lives):

```bash
make build    # Build all Docker images
make up       # Start all services in the background
```

Or combine both in a single step:

```bash
make          # Runs build then up automatically
```

### Stopping the project

| Command | Effect |
|---|---|
| `make down` | Stops and removes containers. All WordPress and database data is preserved on disk. |
| `make clean` | Stops containers and removes dangling Docker images and networks. |
| `make fclean` | Full reset: removes containers, volumes, images, and all data in `~/data`. Use with caution. |

> **`make fclean` is irreversible** and deletes all stored website data. Only use it to start completely from scratch.

### Checking status

```bash
make ps       # List running containers
make logs     # Stream logs from all services
```

---

## 3. Accessing the Website

### 3.1 Public Website

Open your browser and navigate to:

```
https://aruckenb.42.fr
```

> **Note:** Your browser will warn that the certificate is self-signed. This is expected. Click **Advanced** and proceed to the site — the connection is still encrypted.

> **Tip:** HTTP (port 80) is intentionally disabled. Only HTTPS on port 443 is accepted.

### 3.2 Administration Panel

To manage the site's content, users, and settings, go to the WordPress admin area:

```
https://aruckenb.42.fr/wp-admin
```

Two accounts are configured:

| Account | Role | Permissions | Credentials |
|---|---|---|---|
| `aruckenb_owner` | Administrator | Full control: plugins, themes, settings, users | See `wp_admin_password.txt` |
| `editor` | Editor | Create, edit, and publish posts and pages | See `wp_editor_password.txt` |

---

## 4. Locating and Managing Credentials

All credentials are stored as plain-text files in the `secrets/` directory at the project root:

| File | Used By | Purpose |
|---|---|---|
| `db_root_password.txt` | MariaDB init script | Root database superuser |
| `db_password.txt` | MariaDB + WordPress | WordPress application DB user |
| `wp_admin_password.txt` | WordPress setup | WP admin panel login |
| `wp_editor_password.txt` | WordPress setup | WP editor user login |

> ** These files contain plain-text passwords.** Never share, commit, or expose them. The `secrets/` directory should be excluded from version control.

To change a password after first setup, update the relevant `.txt` file and run `make re` to restart the affected container.

---

## 5. Verifying That Services Are Running

### 5.1 Quick Status Check

```bash
make ps
```

You should see three containers — `nginx`, `wordpress`, and `mariadb` — all with status `Up`.

### 5.2 Log Monitoring

```bash
make logs                                                          # All services
docker compose -f srcs/docker-compose.yml logs -f nginx           # NGINX only
docker compose -f srcs/docker-compose.yml logs -f wordpress       # WordPress only
docker compose -f srcs/docker-compose.yml logs -f mariadb         # MariaDB only
```

### 5.3 Verify HTTPS Is Working

```bash
curl -k https://aruckenb.42.fr
```

A successful response contains HTML from WordPress. The `-k` flag tells curl to accept the self-signed certificate.

### 5.4 Verify HTTP Is Blocked

```bash
curl -v http://aruckenb.42.fr
```

This should fail or return a redirect to HTTPS, confirming port 80 is not openly accessible from outside.

---

## 6. Common Operations

### Restarting a Single Service

```bash
docker compose -f srcs/docker-compose.yml restart wordpress
docker compose -f srcs/docker-compose.yml restart nginx
```

### Rebuilding After a Configuration Change

1. Edit the relevant config file or Dockerfile.
2. Run `make re` (or `make build` followed by `make up`).


### Resetting Everything

```bash
make fclean   # Removes all containers, images, volumes, and ~/data
make          # Rebuild and restart from scratch
```

> ** This permanently destroys all posts, users, and settings** stored in WordPress and MariaDB.