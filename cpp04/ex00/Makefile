CC = c++ -std=c++20
NAME = main
CFLAGS = -Wall -Werror -Wextra
SRC = main.cpp Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -I. -o $@ -c $<

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -I. -o $@ $^

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re debug
