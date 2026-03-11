CC = c++ -std=c++20
NAME = phonebook
CFLAGS = -Wall -Werror -Wextra
DFLAGS = -MMD -MP
SRC = main.cpp PhoneBook.cpp Contact.cpp
OBJ = $(SRC:.cpp=.o)
DEP = $(SRC:.cpp=.d)

all: $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) $(DFLAGS) -o $@ -c $<

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

-include $(DEP)

clean:
	rm -f $(OBJ) $(DEP)

fclean: clean
	rm -f $(NAME)

re: fclean all

debug:
	$(MAKE) CFLAGS="$(CFLAGS) -DDEBUG" re

.PHONY: all clean fclean re debug
