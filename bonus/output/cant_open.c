/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cant_open.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarafi <akarafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 00:04:46 by akarafi           #+#    #+#             */
/*   Updated: 2021/12/15 00:11:11 by akarafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	cant_opend(void)
{
	perror("Error\nCan't open this file\n");
	exit(1);
}
