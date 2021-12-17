/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarafi <akarafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:58:35 by akarafi           #+#    #+#             */
/*   Updated: 2021/12/17 01:10:41 by akarafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_node	*head;

	if (ac != 2)
	{
		print_error("Error\nInvalide Args\n");
		return (0);
	}
	check_map(av[1]);
	head = parse_map(av[1]);
	convert_list_to_map(&head);
	find_player();
	render();
}
