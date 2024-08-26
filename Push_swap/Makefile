
NAME = push_swap

SOURCE = push_swap.c algor.c utils.c utils2.c sort.c sort2.c sort3.c ra_b.c pa_b.c rra_b.c 

OBJECTS = $(SOURCE:.c=.o)

CFLAGS = -Wall -Werror -Wextra -g

COMP = cc

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
