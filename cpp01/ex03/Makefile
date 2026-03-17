CC = c++ -std=c++20
NAME = main
CFLAGS = -Wall -Werror -Wextra
DFLAGS = -MMD -MP
SRC = HumanA.cpp \
	  HumanB.cpp \
	  main.cpp \
	  Weapon.cpp \

OBJ = $(SRC:.cpp=.o)
DEP = $(SRC:.cpp=.d)

all: $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) $(DFLAGS) -o $@ -c $<

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

-include $(DEP)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re debug
