CC=cc
CFLAGS= -Wall -Wextra -Werror
LFLAGS= -Llibft -lft -Lmlx_linux -lmlx -lXext -lX11 -lm
SRC= so_long.c map_builder.c map_builder_utils.c
OBJ=$(SRC:%.c=%.o)
NAME=libsolong.a

$(NAME): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC)
	ar -rcs $(NAME) $(OBJ)
	cd libft && $(MAKE)
	cd mlx_linux && $(MAKE)
	$(CC) -o so_long so_long.c $(NAME) $(LFLAGS)

clean:
	rm -f $(OBJ)
	cd libft && $(MAKE) clean
	cd mlx_linux && $(MAKE) clean

fclean: clean
	rm -f $(NAME)
	rm -f so_long
	cd libft && $(MAKE) fclean
	cd mlx_linux && $(MAKE) clean

all: $(NAME)

re: fclean all