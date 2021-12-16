/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarafi <akarafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:58:35 by akarafi           #+#    #+#             */
/*   Updated: 2021/12/16 15:20:03 by akarafi          ###   ########.fr       */
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
	for (int i = 0; i < t_data.hight; i++)
		printf("%s\n", t_data.map[i]);
	printf("number of collectables in map: %d\n", t_data.collectables);
	printf("number of moves: %d\n", t_data.number_of_moves);
	
	printf("player position: (%d, %d)", t_data.player.x + 1, t_data.hight - t_data.player.y);
}
