/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarafi <akarafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 08:22:53 by akarafi           #+#    #+#             */
/*   Updated: 2021/12/15 14:09:54 by akarafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../get_next_line/get_next_line.h"

t_node	*parse_map(char *file_name)
{
	t_node	*head;
	char	*line;
	int		fd;

	head = NULL;
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		cant_opend();
	while (true)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		t_data.hight++;
		line[t_data.len] = 0;
		push(&head, get_new(line));
	}
	return (head);
}
