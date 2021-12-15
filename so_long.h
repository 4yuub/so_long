/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarafi <akarafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:57:49 by akarafi           #+#    #+#             */
/*   Updated: 2021/12/15 12:37:00 by akarafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>
# define FAILED 0
# define SUCCESS 1

struct s_data
{
	int		len;
	int		hight;
	char	**map;
}		t_data;

// output:
void	print_error(char *s);
void	cant_opend(void);

// parsing:
typedef struct s_node
{
	char			*line;
	struct s_node	*next;
}		t_node;
void	check_map(char *file_name);
bool	map_is_valid(char *file_name);
bool	check_closed(char *file_name);
t_node	*parse_map(char *file_name);
void	convert_list_to_map(char *file_name, t_node **head);

// list:
void	pop(t_node **head);
t_node	*get_new(char *content);
void	push(t_node **list, t_node *node);

#endif