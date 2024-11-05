
NAME = philo

SOURCE = main.c ft_itoa.c mutex_thread_creation.c philo_activites.c rountine_tasks.c time.c utils.c utils2.c utils3.c

OBJECTS = $(SOURCE:.c=.o)

CFLAGS = -Wall -Werror -Wextra -g -pthread #-fsanitize=thread,undefined

COMP = cc

RM = rm -f

all: ${NAME}

.c.o:
	${COMP} ${CFLAGS} -c $< -o $@ 

${NAME}: ${OBJECTS}
		${COMP} ${CFLAGS} ${OBJECTS} -o ${NAME}

clean: 
	${RM} ${OBJECTS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re