CC = c++ -std=c++20
NAME = phonebook
CFLAGS = -Wall -Werror -Wextra
DFLAGS = -MMD -MP
SRC = main.cpp PhoneBook.cpp Contact.cpp
OBJ = $(SRC:.cpp=.o)
OBJ_PATH = obj/
OBJS = $(addprefix $(OBJ_PATH), $(OBJ))
DEP = $(addprefix $(OBJ_PATH), $(SRC:.cpp=.d))

all: $(OBJ_PATH) $(NAME)

$(OBJ_PATH)%.o: %.cpp
	$(CC) $(CFLAGS) $(DFLAGS) -o $@ -c $<

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

.SECONDARY: $(OBJS)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

-include $(DEP)

clean:
	rm -f $(OBJS) $(DEP)

fclean: clean
	rm -f $(NAME)

re: fclean all

debug:
	$(MAKE) CFLAGS="$(CFLAGS) -DDEBUG" re

.PHONY: all clean fclean re debug
