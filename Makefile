FILES = main utils show_symbol puttype

SRC = $(foreach f, $(FILES), source/$(f).c)
OBJ = $(foreach f, $(FILES), object/$(f).o)

NAME = nm

CC = cc

CFLAGS = -Wall -Wextra -Werror -Iinclude -g3

all: $(NAME)


$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

object/%.o: source/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all


test: $(NAME)
	@nm nm > ref_nm
	@./nm nm > own_nm

.PHONY: all clean fclean re debug
