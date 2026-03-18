.PHONY: all build up down re logs clean fclean ps

DATA_PATH = /home/$(shell whoami)/data

all: build up

build:
	docker compose -f srcs/docker-compose.yml build

up:
	mkdir -p $(DATA_PATH)/wordpress $(DATA_PATH)/mariadb
	docker compose -f srcs/docker-compose.yml up -d

down:
	docker compose -f srcs/docker-compose.yml down

re: down up

logs:
	docker compose -f srcs/docker-compose.yml logs

clean: down
	docker system prune -f

fclean: clean
	docker compose -f srcs/docker-compose.yml down -v
	docker system prune -a -f
	docker volume rm srcs_wordpress srcs_mariadb 2>/dev/null || true
	sudo rm -rf $(DATA_PATH)

ps:
	docker ps