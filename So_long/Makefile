
NAME = so_long

SOURCE = main.c map_chec.c map_fun.c player_move.c utils.c get_next_line.c get_next_line_utils.c floodfill_con.c

OBJECTS = $(SOURCE:.c=.o)

CFLAGS = -Wall -Werror -Wextra

COMP = cc -g -lmlx -lX11 -lXext -lm

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
