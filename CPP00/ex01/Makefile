NAME := phonebook
HEADERFILES := Phonebook.hpp \
				Contact.hpp
SRCS :=	main.cpp \

FLAGS := -Wall -Wextra -Werror -std=c++98
OBJFILES := $(SRCS:%.cpp=obj/%.o)

all: $(NAME)

$(NAME): $(OBJFILES) 
	clang++ -o $@ $^

obj/%.o: %.cpp $(HEADERFILES)
	@mkdir -p $(dir $@)
	clang++ -c $(FLAGS) -o $@ $<

clean:
	rm -f $(OBJFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re