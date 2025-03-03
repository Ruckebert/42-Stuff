
NAME = testing

SOURCE = Account.cpp tests.cpp

OBJECTS = $(SOURCE:.cpp=.o)

C++FLAGS = -Wall -Werror -Wextra -std=c++98 -fsanitize=undefined

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
