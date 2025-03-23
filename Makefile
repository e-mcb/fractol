CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = hooks.c init.c maths.c render.c utils.c main.c
OBJ = $(SRC:.c=.o)
NAME = fractol
LIBS = -Lminilibx-linux -lmlx_Linux -lX11 -lXext
HEADER = fractol.h
MINILIBX_DIR = minilibx-linux
MINILIBX_MAKEFILE = $(MINILIBX_DIR)/Makefile

all: $(NAME)

$(NAME): $(OBJ) | $(MINILIBX_DIR)/libmlx.a
	$(CC) $(OBJ) $(LIBS) -o $(NAME)

$(MINILIBX_DIR)/libmlx.a:
	$(MAKE) -C $(MINILIBX_DIR)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(MINILIBX_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(MINILIBX_DIR) fclean

re: fclean all

.PHONY: all clean fclean re

