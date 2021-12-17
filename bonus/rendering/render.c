/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarafi <akarafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 00:40:19 by akarafi           #+#    #+#             */
/*   Updated: 2021/12/17 23:34:24 by akarafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../string/ft_string.h"

void	put_img(t_img *img, int x, int y)
{
	mlx_put_image_to_window(t_data.mlx, \
		t_data.window, img->data, x * 30, y * 30);
}

void	put_img_of(int x, int y)
{
	char	c;

	c = t_data.map[y][x];
	if (c == 'P')
		put_img(t_data.player_img, x, y);
	else if (c == 'E')
		put_img(t_data.house, x, y);
	else if (c == '1')
		put_img(t_data.stone, x, y);
	else if (c == 'C')
		put_img(t_data.collectable, x, y);
	else if (c == 'X')
	{
		if (rand() % 3 == 0 || rand() % 3 == 1)
			put_img(t_data.bat, x, y);
		else
			put_img(t_data.bat2, x, y);
	}
}

int	move_player(int key, void *x)
{
	(void) x;
	mlx_clear_window(t_data.mlx, t_data.window);
	if (key == 53)
		exit(0);
	if (key == 13)
		move_up();
	else if (key == 0)
		move_left();
	else if (key == 2)
		move_right();
	else if (key == 1)
		move_down();
	render();
	return (0);
}

void	update_number_of_moves(void)
{
	char	*s;

	if (!t_data.buff)
		free(t_data.buff);
	s = ft_itoa(t_data.number_of_moves);
	t_data.buff = ft_strjoin("number of moves: ", s);
	free(s);
}

void	render(void)
{
	int	x;
	int	y;

	y = -1;
	load_imgs();
	while (++y < t_data.hight)
	{
		x = -1;
		while (++x < t_data.len)
		{
			put_img(t_data.background, x, y);
			put_img_of(x, y);
		}	
	}
	update_number_of_moves();
	mlx_string_put(t_data.mlx, t_data.window, 30, 0, \
		0xf3f3f3, t_data.buff);
	mlx_hook(t_data.window, 2, 1L, move_player, NULL);
	mlx_hook(t_data.window, 17, 1L, distroy, 0);
	mlx_loop(t_data.mlx);
}
