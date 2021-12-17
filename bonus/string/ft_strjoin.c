/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarafi <akarafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 22:09:20 by akarafi           #+#    #+#             */
/*   Updated: 2021/12/17 22:13:34 by akarafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "ft_string.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		l;
	int		i;
	int		j;
	char	*joined;

	if (!s1 || !s2)
		return (0);
	l = ft_strlen(s1) + ft_strlen(s2);
	joined = (char *) malloc(l + 1);
	if (!joined)
		return (joined);
	i = 0;
	while (s1[i])
	{
		joined[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		joined[i + j] = s2[j];
		j++;
	}
	joined[i + j] = '\0';
	return (joined);
}
