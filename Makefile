all:
	cc -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit *.c */*.c
fclean:
	rm so_long