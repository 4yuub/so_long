/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarafi <akarafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 14:59:24 by akarafi           #+#    #+#             */
/*   Updated: 2021/12/16 15:17:27 by akarafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	find_player(void)
{
	int		x;
	int		y;
	bool	found;

	y = -1;
	found = false;
	while (++y < t_data.hight)
	{
		x = -1;
		while (++x < t_data.len)
		{
			if (t_data.map[y][x] == 'P')
			{
				t_data.player.x = x;
				t_data.player.y = y;
				found = true;
				break ;
			}
		}
		if (found)
			break ;
	}
}
