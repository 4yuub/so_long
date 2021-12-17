/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarafi <akarafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:57:49 by akarafi           #+#    #+#             */
/*   Updated: 2021/12/17 21:58:09 by akarafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>
# include <mlx.h>
# define FAILED 0
# define SUCCESS 1

typedef struct s_position
{
	int	x;
	int	y;
}		t_position;

typedef struct s_img
{
	void	*data;
	int		hight;
	int		width;
}		t_img;

struct s_data
{
	int			len;
	int			hight;
	char		**map;
	int			collectables;
	int			number_of_moves;
	t_position	player;
	void		*mlx;
	void		*window;
	t_img		*player_img;
	t_img		*collectable;
	t_img		*house;
	t_img		*stone;
	t_img		*background;
	char		*buff;
}		t_data;

// output:
void	print_error(char *s);
void	cant_opend(void);

// parsing:
typedef struct s_node
{
	char			*line;
	struct s_node	*next;
}		t_node;
void	check_map(char *file_name);
bool	map_is_valid(char *file_name);
bool	check_closed(char *file_name);
t_node	*parse_map(char *file_name);
void	convert_list_to_map(t_node **head);

// list:
void	pop(t_node **head);
t_node	*get_new(char *content);
void	push(t_node **list, t_node *node);

// game play:
void	find_player(void);
void	move(t_position	position);
void	move_up(void);
void	move_down(void);
void	move_left(void);
void	move_right(void);

// rendring:
void	render(void);
void	load_imgs(void);
int		distroy(int n);

#endif