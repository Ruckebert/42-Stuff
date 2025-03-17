
NAME = harlFilter

SOURCE = main.cpp Harl.cpp

OBJECTS = $(SOURCE:.cpp=.o)

CXXFLAGS = -Wall -Werror -Wextra -std=c++98

CXX = c++

RM = rm -f

all: ${NAME}

.c.o:
	${CXX} ${CXXFLAGS} -c $< -o $@ 

${NAME}: ${OBJECTS}
		${CXX} ${CXXFLAGS} ${OBJECTS} -o ${NAME}

clean: 
	${RM} ${OBJECTS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
