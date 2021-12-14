/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarafi <akarafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 18:59:59 by akarafi           #+#    #+#             */
/*   Updated: 2021/12/14 17:03:40 by akarafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"
#include "../string/ft_string.h"

char	*get_next_line(int fd)
{
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	return (main_func(fd));
}

char	*main_func(int fd)
{
	static char	*full[65535];
	char		*line;
	char		buffer[BUFFER_SIZE + 1];
	int			n;

	if (line_in_full(full[fd]))
	{
		line = get_line(full[fd]);
		full[fd] = trim(full[fd]);
		if (!full[fd])
			return (NULL);
		return (line);
	}
	n = read(fd, buffer, BUFFER_SIZE);
	if (n <= 0)
	{
		line = line_or_null(full[fd]);
		full[fd] = NULL;
		return (line);
	}
	buffer[n] = 0;
	full[fd] = add_buffer_to_full(buffer, full[fd]);
	if (!full[fd])
		return (NULL);
	return (main_func(fd));
}

char	*add_buffer_to_full(char *buffer, char *full)
{
	char	*tmp;

	if (!full)
		full = ft_strdup("");
	tmp = ft_strdup(full);
	free(full);
	full = malloc(ft_strlen(tmp) + ft_strlen(buffer) + 1);
	if (!full)
	{
		free(tmp);
		return (0);
	}
	*full = 0;
	ft_strcat(full, tmp);
	ft_strcat(full, buffer);
	free(tmp);
	return (full);
}

char	*trim(char *full)
{
	char	*tmp;
	int		i;

	i = 0;
	if (!full)
		return (NULL);
	while (full[i] && full[i] != '\n')
		i++;
	tmp = ft_strdup(full + i + 1);
	if (!tmp)
		return (NULL);
	free(full);
	full = tmp;
	return (full);
}

char	*get_line(char *full)
{
	char	*line;
	int		i;

	i = 0;
	if (!full)
		return (NULL);
	while (full[i] && full[i] != '\n')
		i++;
	line = malloc(i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (full[i] && full[i] != '\n')
	{
		line[i] = full[i];
		i++;
	}
	line[i] = full[i];
	line[++i] = '\0';
	return (line);
}
