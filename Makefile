SRC = main.c utils.c show_symbol.c
OBJ = main.o utils.o show_symbol.o

NAME = nm

CC = cc

CFLAGS = -Wall -Wextra -Werror -I.

all: $(NAME)


$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all


.PHONY: all clean fclean re debug
