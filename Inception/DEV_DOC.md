Show how to set up the environment from scratch


Build and launch the project *bascially a description in how to use the make file 
make build
make up
make re
make down

Use revelevant commands to manage the containers and volumes

Identify where the project data is stored 

SQL Commands

This allows access to the sql!
docker compose -f srcs/docker-compose.yml exec mariadb mysql -u root -p

-- Show all databases
SHOW DATABASES;

-- Select WordPress database
USE wordpress_db;

-- Show all tables
SHOW TABLES;

-- View WordPress users
SELECT ID, user_login, user_email, user_registered FROM wp_users;

-- View WordPress posts
SELECT ID, post_title, post_status, post_type FROM wp_posts;

-- View WordPress comments
SELECT comment_ID, comment_author, comment_content FROM wp_comments;

-- View all options (site settings)
SELECT option_name, option_value FROM wp_options;

-- Exit
EXIT;

Use this command to check if port 80 is connectable it should fail
curl -v http://aruckenb.42.fr 