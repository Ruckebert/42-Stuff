
NAME = philosphers

SOURCE = ft_atoi.c ft_bzero.c main.c

OBJECTS = $(SOURCE:.c=.o)

CFLAGS = -Wall -Werror -Wextra -g

COMP = cc -lmlx -lX11 -lXext -lm

RM = rm -f

all: ${NAME}

.c.o:
	-cc ${CFLAGS} -c $< -o ${<:.c=.o} 

${NAME}: ${OBJECTS} 
		${MAKE} -C ./libft --no-print-directory
		${COMP} ${CFLAGS} ${OBJECTS} ./libft/libft.a -o ${NAME}

clean: 
	${MAKE} -C ./libft --no-print-directory fclean
	${RM} ${OBJECTS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
