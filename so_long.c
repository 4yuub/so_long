/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarafi <akarafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:58:35 by akarafi           #+#    #+#             */
/*   Updated: 2021/12/15 08:52:48 by akarafi          ###   ########.fr       */
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
	fd = open(av[1], O_RDONLY);
	head = parse_map(fd);
	while (head)
	{
		printf("%s\n", head->line);
		head = head->next;
	}
}
