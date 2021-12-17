all:
	cc -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit *.c */*.c -o so_long
fclean:
	rm so_long