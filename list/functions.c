/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarafi <akarafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 14:09:24 by akarafi           #+#    #+#             */
/*   Updated: 2021/12/15 14:12:44 by akarafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	pop(t_node **head)
{
	t_node	*tmp_node;

	if (!head || !*head)
		return ;
	tmp_node = (*head)->next;
	free(*head);
	(*head) = tmp_node;
}

t_node	*get_new(char *content)
{
	t_node	*node;

	node = (t_node *) malloc(sizeof(t_node));
	if (!node)
		return (node);
	node->line = content;
	node->next = NULL;
	return (node);
}

void	push(t_node **list, t_node *node)
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
