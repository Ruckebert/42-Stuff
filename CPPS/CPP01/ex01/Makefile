
NAME = Brainzzzz

SOURCE = main.cpp newZombie.cpp randomChump.cpp Zombie.cpp

OBJECTS = $(SOURCE:.cpp=.o)

C++FLAGS = -Wall -Werror -Wextra -std=c++98

C++ = c++

RM = rm -f

all: ${NAME}

.c.o:
	${C++} ${C++FLAGS} -c $< -o $@ 

${NAME}: ${OBJECTS}
		${C++} ${C++FLAGS} ${OBJECTS} -o ${NAME}

clean: 
	${RM} ${OBJECTS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
