/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarafi <akarafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:58:35 by akarafi           #+#    #+#             */
/*   Updated: 2021/12/16 18:40:34 by akarafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	int		fd;
	t_node	*head;

	if (ac != 2)
	{
		print_error("Error\nInvalide Args\n");
		return (0);
	}
	check_map(av[1]);
	head = parse_map(av[1]);
	convert_list_to_map(av[1], &head);
	find_player();
	move_up();
	move_down();
	move_right();
	move_left();
	printf("number of collectables in map: %d\n", t_data.collectables);
}
