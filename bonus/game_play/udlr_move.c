/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   udlr_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarafi <akarafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 18:25:01 by akarafi           #+#    #+#             */
/*   Updated: 2021/12/16 18:41:42 by akarafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// udlr stands for (up down left righ)
#include "../so_long.h"

void	move_up(void)
{
	t_position	p;

	p.x = t_data.player.x;
	p.y = t_data.player.y - 1;
	move(p);
}

void	move_down(void)
{
	t_position	p;

	p.x = t_data.player.x;
	p.y = t_data.player.y + 1;
	move(p);
}

void	move_left(void)
{
	t_position	p;

	p.x = t_data.player.x - 1;
	p.y = t_data.player.y;
	move(p);
}

void	move_right(void)
{
	t_position	p;

	p.x = t_data.player.x + 1;
	p.y = t_data.player.y;
	move(p);
}
