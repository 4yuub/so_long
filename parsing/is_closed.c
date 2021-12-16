/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_closed.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarafi <akarafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 23:28:23 by akarafi           #+#    #+#             */
/*   Updated: 2021/12/16 21:35:26 by akarafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line/get_next_line.h"
#include "../so_long.h"

static void	check_first_and_last(char *s, bool last)
{
	while (*s && *s != '\n')
	{
		if (*s != '1')
		{
			print_error("Error\nInvalid Map!\n");
			exit(0);
		}
		s++;
	}
	if (last && *s == '\n')
	{
		print_error("Error\nInvalid Map!\n");
		exit(0);
	}
}

static void	check_middle_lines(char *s)
{
	if (*s != '1' || s[t_data.len - 1] != '1')
	{
		print_error("Error\nInvalid Map!\n");
		exit(0);
	}
}

bool	check_closed(char *file_name)
{
	int		fd;
	char	*s;
	char	*previous;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		cant_opend();
	s = get_next_line(fd);
	if (!s)
		return (close(fd), false);
	check_first_and_last(s, false);
	while (true)
	{
		previous = s;
		s = get_next_line(fd);
		if (!s)
		{
			check_first_and_last(previous, true);
			free(previous);
			break ;
		}
		check_middle_lines(s);
		free(previous);
	}
	return (close(fd), true);
}
