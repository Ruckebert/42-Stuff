
NAME = Bureaucrat

SOURCE = main.cpp Bureaucrat.cpp AForm.cpp PresidentialPardonForm.cpp ShrubbyCreationForm.cpp RobotomyRequestForm.cpp

OBJECTS = $(SOURCE:.cpp=.o)

DEPS =  $(SOURCE:.cpp=.d)

CXXFLAGS = -Wall -Werror -Wextra -std=c++98

DFLAGS = -MP -MMD

CXX = c++

RM = rm -f

all: ${NAME}

%.o : %.cpp
	${CXX} ${CXXFLAGS} ${DFLAGS} -c $< -o $@ 

${NAME}: ${OBJECTS}
		${CXX} ${CXXFLAGS} ${DFLAGS} ${OBJECTS} -o ${NAME}

clean: 
	${RM} ${OBJECTS} $(DEPS)

fclean:
	${RM} ${OBJECTS} $(DEPS) ${NAME}

re:
	${RM} ${OBJECTS} $(DEPS) ${NAME}
	$(MAKE) all

-include $(DEPS)

.PHONY: all clean fclean re
