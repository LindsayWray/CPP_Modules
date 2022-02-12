NAME := forms
HEADERFILES :=	Bureaucrat.hpp \
				Form.hpp \
				ShrubberyCreationForm.hpp \
				RobotomyRequestForm.hpp \
				PresidentialPardonForm.hpp
SRCS :=			main.cpp \
				Bureaucrat.cpp \
				Form.cpp \
				ShrubberyCreationForm.cpp \
				RobotomyRequestForm.cpp \
				PresidentialPardonForm.cpp

FLAGS := -Wall -Wextra -Werror -std=c++98 -pedantic
OBJFILES := $(SRCS:%.cpp=obj/%.o)

all: $(NAME)

$(NAME): $(OBJFILES) 
	c++ -o $@ $^

obj/%.o: %.cpp $(HEADERFILES)
	@mkdir -p $(dir $@)
	c++ -c $(FLAGS) -o $@ $<

clean:
	rm -f $(OBJFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all