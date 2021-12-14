/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarafi <akarafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 15:09:04 by akarafi           #+#    #+#             */
/*   Updated: 2021/12/14 23:07:02by akarafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../get_next_line/get_next_line.h"
#include "../string/ft_string.h"

static bool	check_lenght(char *file_name)
{
	int		fd;
	char	*s;
	int		len;
	int		tmp_len;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
	{
		perror("Error\nCan't open this file\n");
		exit(1);
	}
	s = get_next_line(fd);
	len = ft_strlen_nl(s);
	free(s);
	while (true)
	{
		s = get_next_line(fd);
		if (!s)
			break ;
		tmp_len = ft_strlen_nl(s);
		free(s);
		if (len != tmp_len)
			return (close(fd), false);
	}
	return (close(fd), true);
}

static void	count_and_check(char *s, int	*c, int	*p, int *e)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '\n')
	{
		if (s[i] == 'E')
			(*e)++;
		else if (s[i] == 'P')
			(*p)++;
		else if (s[i] == 'C')
			(*c)++;
		else if (s[i] != '1' && s[i] != '0')
		{
			free(s);
			print_error("Error\nInvalid Map!\n");
			exit(0);
		}
		i++;
	}
}

static bool	check_existance(char *file_name)
{
	int		fd;
	int		collectables;
	int		players;
	int		exits;
	char	*s;

	collectables = 0;
	players = 0;
	exits = 0;
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
	{
		perror("Error\nCan't open this file\n");
		exit(1);
	}
	while (true)
	{
		s = get_next_line(fd);
		if (!s)
			break ;
		count_and_check(s, &collectables, &players, &exits);
		free(s);
	}
	return (players == 1 && exits >= 1 && collectables >= 1);
}

bool	map_is_valid(char *file_name)
{
	char	*s;
	bool	lines_lenght;
	bool	closed_map;
	bool	building_blocks_existance;

	// closed_map = check_closed(file_name);
	lines_lenght = check_lenght(file_name);
	building_blocks_existance = check_existance(file_name);
	return (lines_lenght && building_blocks_existance);// && closed_map);
}
