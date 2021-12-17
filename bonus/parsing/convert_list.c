/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarafi <akarafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 12:17:31 by akarafi           #+#    #+#             */
/*   Updated: 2021/12/17 01:09:50 by akarafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	convert_list_to_map(t_node **head)
{
	t_node	*tmp;
	int		i;

	t_data.map = malloc(t_data.hight * sizeof(char *));
	tmp = *head;
	i = 0;
	while (tmp)
	{
		t_data.map[i] = tmp->line;
		tmp = tmp->next;
		i++;
	}
	while (head && *head)
		pop(head);
}
