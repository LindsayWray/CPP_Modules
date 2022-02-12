NAME := animals
HEADERFILES := Animal.hpp Dog.hpp Cat.hpp Brain.hpp
SRCS :=	main.cpp Animal.cpp Dog.cpp Cat.cpp Brain.cpp

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
