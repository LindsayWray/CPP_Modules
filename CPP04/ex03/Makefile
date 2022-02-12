NAME := interface
HEADERFILES :=	Materia/AMateria.hpp \
				Materia/Cure.hpp \
				Materia/Ice.hpp \
				Character/Character.hpp \
				Character/ICharacter.hpp \
				MateriaSource/MateriaSource.hpp \
				MateriaSource/IMateriaSource.hpp
SRCS :=			main.cpp \
				Materia/AMateria.cpp \
				Materia/Cure.cpp \
				Materia/Ice.cpp \
				Character/Character.cpp \
				MateriaSource/MateriaSource.cpp

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
