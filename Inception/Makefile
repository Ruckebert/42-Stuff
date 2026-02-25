.PHONY: all build up down re logs clean fclean

DATA_PATH = /home/$(shell whoami)/data

all: build up

build:
	docker-compose -f srcs/docker-compose.yml build

up:
	mkdir -p $(DATA_PATH)/wordpress $(DATA_PATH)/mariadb
	docker-compose -f srcs/docker-compose.yml up -d

down:
	docker-compose -f srcs/docker-compose.yml down

re: down up

logs:
	docker-compose -f srcs/docker-compose.yml logs -f

clean:
	docker-compose -f srcs/docker-compose.yml down -v

fclean: clean
	docker system prune -a
	rm -rf $(DATA_PATH)

ps:
	docker-compose -f srcs/docker-compose.yml ps