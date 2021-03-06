/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarafi <akarafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:30:37 by akarafi           #+#    #+#             */
/*   Updated: 2021/12/17 23:26:34 by akarafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../string/ft_string.h"

static bool	check_postion(t_position p)
{
	char	c;

	if (p.x > t_data.len - 1 || p.y > t_data.hight - 1)
		return (false);
	if (p.x < 0 || p.y < 0)
		return (false);
	c = t_data.map[p.y][p.x];
	if (c == '1')
		return (false);
	if (c == 'X')
	{
		printf("You lost\n");
		exit(0);
	}
	if (c == 'E' && t_data.collectables != 0)
		return (false);
	if (c == 'C')
		t_data.collectables--;
	return (true);
}

void	move(t_position	position)
{
	if (!check_postion(position))
		return ;
	t_data.number_of_moves++;
	t_data.map[t_data.player.y][t_data.player.x] = '0';
	if (t_data.map[position.y][position.x] == 'E')
	{
		printf("You win\n");
		exit(0);
	}
	t_data.map[position.y][position.x] = 'P';
	t_data.player.x = position.x;
	t_data.player.y = position.y;
}
