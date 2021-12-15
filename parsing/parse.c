/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarafi <akarafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 08:22:53 by akarafi           #+#    #+#             */
/*   Updated: 2021/12/15 08:52:32 by akarafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../get_next_line/get_next_line.h"

static void	pop(t_node **head)
{
	t_node	*tmp_node;

	if (!head || !*head)
		return ;
	tmp_node = (*head)->next;
	free(*head);
	(*head) = tmp_node;
}

static t_node	*get_new(char *content)
{
	t_node	*node;

	node = (t_node *) malloc(sizeof(t_node));
	if (!node)
		return (node);
	node->line = content;
	node->next = NULL;
	return (node);
}

static void	push(t_node **list, t_node *node)
{
	t_node	*last_node;

	if (!list)
		return ;
	if (!*list)
	{
		*list = node;
		return ;
	}
	last_node = *list;
	while (last_node->next)
		last_node = last_node->next;
	last_node->next = node;
}

t_node	*parse_map(int fd)
{
	t_node	*head;
	char	*line;

	head = NULL;
	while (true)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		line[t_data.len] = 0;
		push(&head, get_new(line));
	}
	return (head);
}
