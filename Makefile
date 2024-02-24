SRC = main.c utils.c show_symbol.c puttype.c
OBJ = main.o utils.o show_symbol.o puttype.o

NAME = nm

CC = cc

CFLAGS = -Wall -Wextra -Werror -I. -g3

all: $(NAME)


$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all


.PHONY: all clean fclean re debug
