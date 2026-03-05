CC = c++ -std=c++20
NAME = phonebook
CFLAGS = -Wall -Werror -Wextra
SRC = main.cpp PhoneBook.cpp Contact.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$.o: $.cpp
	$(CC) $(CFLAGS) -I. -o $@ -c $<

$(NAME): $(OBJ)
	$(CC) -I. -o $@ $^

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
