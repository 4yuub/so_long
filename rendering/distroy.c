/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarafi <akarafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 06:36:23 by akarafi           #+#    #+#             */
/*   Updated: 2021/12/17 06:37:37 by akarafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	__distroy(void)
{
	mlx_destroy_window(t_data.mlx, t_data.window);
	exit(0);
}

int	distroy(int n)
{
	__distroy();
	return (n);
}
