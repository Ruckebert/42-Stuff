*This project has been created as part of the 42 curriculum by aruckeb*

# Inception - Basic Docker 

## Description

Inception aims to broaden your knowledge of system administration by using Docker. You will virtualize several Docker images (NGINX, Mariadb and Wordpress), creating them in your new personal virtual machine (the one Im using is Ubuntu). 

## Instructions

To Compile the projet, run:

'''bash make build'''  - This will build up the containers and images

'''bash make up'''  - This makes up each of the images

'''bash make down''' - This command builds the containers down

'''bash make fclean''' - cleans all the containers and removes the data stored it inside

'''bash make ps''' - executes docker ps


## Resources
Docker Basic Turtorial - https://docker-curriculum.com/ 

Mariadb Basic Tutorial - https://www.mariadbtutorial.com/

NGINX Basic Tutorial - https://nginx.org/en/docs/beginners_guide.html 

### AI Usage
AI was primarily used to aid in understanding Docker, MariaDB, and NGINX, as well as helping fix and understand errors. It also assisted in developing the README, user, and dev documents.

## Project description 
### What is docker used for ? 
Docker is a conainerization platform that packages applications and their dependencies into isolated containers. 

Its often used for:

Consistency: Having the same environment across development, testing and production

Isolation: Each Container runs independently without affecting others

Efficiency: Lightweight compared to a virtual machine requiring only 100 - 500mb 

Scalability: It is easy to run multiple instances of a service

Portability: Docker can run anywhere that is installed on

### how does mariadb, nginx, wordpress work?
#### MariaDB (Database)
MariaDB is an Open-source relational database, in the case of inception it stores all the wordpress data and runs it in its own container with peristent storage via Docker volumes. Some of the data the is require for the database is either in the environment file .env or in the Dokcer secrets(secrets folder)

#### NGINX (Web Server)
Acts as a reverse proxy and load, balancer which in this case listens for port 4443 for incomming HTTP/HTTPS requests and routes the request to the wordpress cotainer. NGINX also handles the SSL/TLS encryption.

#### Wordpress (Content Management System or CMS Application)
A PHP-based content management system that runs in it own container connecting to MariaDB for the database storage. It recieves the requests from NGINX (however it doesnt handle the direct HTTP/HTTPS connection). It uses Volumes to amintain the files and themes uploaded.

## Virtual Machines Vs docker
### What is a Virtual Machine?
A Virtual Machine (VM) is a software emulation of a complete computer system that runs an entire operating system (OS). It includes a complete operating system kernel, drivers and utilities. Hardware emulation simulating CPU, RAM, disk, network interfaces, this makes it completely isolatied from the host machine. This would also mean that the virtual machine requires large amounts of space (this also depends on the OS system your using) typically requiruing around 1 - 20GB of disk space.

### Key Differences: VMs vs Docker

| Aspect | Virtual Machine | Docker Container |
|--------|----------------|-----------------|
| **Size** | 1–20 GB | 100–500 MB |
| **Startup Time** | Minutes | Seconds |
| **Resource Usage** | Heavy (full OS) | Lightweight (shared kernel) |
| **Isolation** | Complete isolation | Process-level isolation |
| **Portability** | Less portable | Highly portable |
| **Overhead** | High | Minimal |

### Why Docker Instead of VMs for Inception?
For this project the best is none other then docker, since inception only requires running 3 services (NGINX, MariaDB, WordPress) and using a VMs is extremely excessive. Docker is much more resource efficient using fair less resources while still providing the necessary isolation. Using and managing Docker containers is much simpler and easier then using a virtual machine this is shown by the clear speed differences. With the simple management it is easier to increase and expand the scalability of the containers. In summary Docker provides sufficient isolation and security that is require for this project while being lightweight and efficient.

## Secrets vs Environment variables
Environment Variables hold non-sensitive configuration (ports, feature flags, hostnames). They're easy to set and change per environment, but are visible in plain text in your docker-compose.yml and to any process inside the container — not safe for passwords or tokens.

Docker Secrets are designed for sensitive data like passwords and API keys. They're stored encrypted, not exposed in your compose file, and only mounted inside the containers that explicitly need them — making them far more secure for credentials.


## Docker Network vs Host Network
Docker Network (the default bridge mode) gives each container its own isolated network namespace. Containers communicate with each other by name, and you explicitly control which ports are exposed to the outside world — keeping things contained and secure.

Host Network removes that isolation and lets the container share the host machine's network stack directly. This gives better performance (no NAT overhead) but means the container can bind to any host port freely, which reduces isolation and can cause port conflicts.

## Docker Volumes vs Bind Mounts
Docker Volumes are managed entirely by Docker and stored in Docker's own directory on the host. They're the recommended way to persist data — portable, easy to back up, and work consistently across environments and operating systems.

Bind Mounts map a specific path on your host machine directly into the container. They're great for development (e.g. live-reloading source code), but are tightly coupled to your host's file structure, making them less portable and harder to manage in production.
