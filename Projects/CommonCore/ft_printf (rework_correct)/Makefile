
NAME = libftprintf.a

SOURCE = ft_printf.c ft_putchar_print.c ft_putnbr_count.c ft_putnbr_hex.c ft_putnbr_pointhex.c ft_putnbr_unsigned.c ft_putstr_print.c

OBJECTS = $(SOURCE:.c=.o)

CFLAGS = -Wall -Werror -Wextra

AR = ar rcs

RM = rm -f

all: ${NAME}

.c.o:
	-cc ${CFLAGS} -c $< -o ${<:.c=.o} 

${NAME}: ${OBJECTS}
		${AR} ${NAME} ${OBJECTS}

clean: 
	${RM} ${OBJECTS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
