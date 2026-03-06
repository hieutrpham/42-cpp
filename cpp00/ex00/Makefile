CC = c++ -std=c++20
NAME = megaphone
CFLAGS = -Wall -Werror -Wextra
SRC = megaphone.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS)  -o $@ -c $<

$(NAME): $(OBJ)
	$(CC) -o $@ $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re debug
