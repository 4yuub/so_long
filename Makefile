CC = @cc
NAME = so_long
CFLAGS = -Wall -Wextra -Werror
INC = so_long.h string/ft_string.h get_next_line/get_next_line.h
RM = @rm -rf

# SRCS:
GAME_PLAY = find_player.c move_player.c udlr_move.c
GNL = get_next_line.c get_next_line_utils.c
LST = functions.c
OUTPUT = cant_open.c error.c
PARSING = check_map.c convert_list.c is_closed.c is_valid.c parse.c
RENDERING = distroy.c load.c render.c
STRING = ft_strlen.c ft_strlen_nl.c ft_strncmp.c

SRCS =	$(addprefix game_play/, $(GAME_PLAY))\
		$(addprefix get_next_line/, $(GNL))\
		$(addprefix list/, $(LST))\
		$(addprefix output/, $(OUTPUT))\
		$(addprefix parsing/, $(PARSING))\
		$(addprefix rendering/, $(RENDERING))\
		$(addprefix string/, $(STRING))\
		so_long.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS)  -o $@ -lmlx -framework OpenGL -framework AppKit
	@echo "Code compiled successfully"

%.o:%.c $(INC)
	@echo "compiling..."
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	@echo "object files removed successfully"

fclean: clean
	$(RM) $(NAME)
	@echo "so_long executable removed successfully"

re: fclean all

.PHONY: fclean clean all re