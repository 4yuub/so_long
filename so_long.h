/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarafi <akarafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:57:49 by akarafi           #+#    #+#             */
/*   Updated: 2021/12/14 17:01:00 by akarafi          ###   ########.fr       */
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

// output:
void	print_error(char *s);

// parsing:
void	check_map(char *file_name);
bool	map_is_valid(char *file_name);

#endif