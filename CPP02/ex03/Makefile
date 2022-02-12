NAME := fixed
HEADERFILES := Fixed.hpp Point.hpp
SRCS :=	main.cpp Fixed.cpp Point.cpp bsp.cpp

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