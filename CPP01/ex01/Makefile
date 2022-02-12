NAME := zombies
HEADERFILES := Zombie.hpp
SRCS :=	main.cpp Zombie.cpp ZombieHorde.cpp

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

.PHONY: all clean fclean re