Understand what services are provided by the stack
#Inceptions provides 3 main stack services:

1.NGINX (Web server)
-Listens on port 433 (HTTPS ONLY!)
-Serves Wordpress
-Uses the TLSv1.2 certificate
-Acts as a reverse proxy to PHP-FPM

2.Wordpress + PHP-FPM (Application)
-Runs Wordpress
-PHP-FPM process PHP requests
-Connects to the MariaDB database
-Stores files in /var/www/wordpress volume

3.MariaDB (Database)
-MySQL-compatible database erver
-Stores Wordpress data (i.e. posts, users, comments, etc)
-Data persists in the mysql volume

How Everything Works Together 

User Browser (HTTPS) -> NGINX (Port 443) -> PHP-FPM -> Wordpress -> MariaDB

! All these Services can be seen in the docker-compose.yml file under the service tag.

Start and stop the project

Starting the Project
in order to run the project, start with make build, the make up

Stopping the Project
Once everything is done excuting they are 2 ways to stop the project, make fclean which deletes all clears all the containers or make down which builds down the containers but they still retain the data.

Access the website
In order to access the website the user must type https://aruckenb.42.fr

Administration Panel 
In order to acces the website administration panel the user must type https://aruckenb.42.fr/wp-admin 
They must then enter either the admin username and password or the editors username and password (*Note editor is simply another user that was required by the subject)

locate and manage credentials?

Check the services are running correctly 
To check is everything is running the user can type either make log or docker compose ls 