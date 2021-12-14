/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarafi <akarafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 15:09:04 by akarafi           #+#    #+#             */
/*   Updated: 2021/12/14 17:02:14 by akarafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../get_next_line/get_next_line.h"
#include "../string/ft_string.h"

bool	check_lenght(char *file_name)
{
	int		fd;
	char	*s;
	int		len;
	int		tmp_len;

	fd = open(file_name, O_RDONLY);
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

bool	map_is_valid(char *file_name)
{
	char	*s;
	bool	lines_lenght;
	bool	closed_map;
	bool	building_blocks_existance;

	lines_lenght = check_lenght(file_name);
	// closed_map = check_closed(file_name);
	// building_blocks_existance = check_existance(file_name);
	return (lines_lenght);// && building_blocks_existance && closed_map);
}
