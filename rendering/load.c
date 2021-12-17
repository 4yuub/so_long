/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarafi <akarafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 23:48:07 by akarafi           #+#    #+#             */
/*   Updated: 2021/12/17 01:06:33 by akarafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static t_img	*load_img(char *filepath)
{
	t_img	*img;

	img = (t_img *)malloc(sizeof(t_img));
	if (!img)
	{
		perror("allocation failed\n");//free
		exit(1);
	}
	img->data = mlx_xpm_file_to_image(t_data.mlx, filepath, \
		&img->width, &img->hight);
	return (img);
}

void	load_imgs(void)
{
	t_data.player_img = load_img("./imgs/player.xpm");
	t_data.collectable = load_img("./imgs/collec.xpm");
	t_data.house = load_img("./imgs/house.xpm");
	t_data.stone = load_img("./imgs/stone.xpm");
	t_data.background = load_img("./imgs/background.xpm");
}
