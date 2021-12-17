/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarafi <akarafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:57:59 by akarafi           #+#    #+#             */
/*   Updated: 2021/12/17 01:10:32 by akarafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../string/ft_string.h"

static void	check_file_name(char *file_name)
{
	int	len;

	len = ft_strlen(file_name);
	if (!ft_strncmp(file_name + len - 4, ".ber", 4))
	{
		print_error("Error\nFile name must end with \".ber\"\n");
		exit(0);
	}
}

void	check_map(char *file_name)
{
	int	fd;

	check_file_name(file_name);
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		cant_opend();
	if (!map_is_valid(file_name))
	{
		print_error("Error\nInvalid Map!\n");
		exit(1);
	}
}
