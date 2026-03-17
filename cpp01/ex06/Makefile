CC = c++ -std=c++20
NAME = harlFilter
CFLAGS = -Wall -Werror -Wextra
SRC = main.cpp Harl.cpp

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
