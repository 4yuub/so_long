/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarafi <akarafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 00:40:19 by akarafi           #+#    #+#             */
/*   Updated: 2021/12/17 02:10:17 by akarafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
}

void	render(void)
{
	int	x;
	int	y;

	y = -1;
	t_data.mlx = mlx_init();
	load_imgs();
	t_data.window = mlx_new_window(t_data.mlx, \
		t_data.len * 30, t_data.hight * 30, "So_long");
	while (++y < t_data.hight)
	{
		x = -1;
		while (++x < t_data.len)
		{
			put_img(t_data.background, x, y);
			put_img_of(x, y);
		}	
	}
	mlx_loop(t_data.mlx);
}
