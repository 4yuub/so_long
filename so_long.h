/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarafi <akarafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:57:49 by akarafi           #+#    #+#             */
/*   Updated: 2021/12/15 08:47:02 by akarafi          ###   ########.fr       */
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
	int	len;
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
t_node	*parse_map(int fd);

#endif