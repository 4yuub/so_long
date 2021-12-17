/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarafi <akarafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:58:06 by akarafi           #+#    #+#             */
/*   Updated: 2021/12/17 22:13:41 by akarafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

int		ft_strncmp( char *s1, char *s2, int n);
int		ft_strlen(char *s);
int		ft_strlen_nl(char *s);
char	*ft_itoa(int nb);
char	*ft_strjoin(char *s1, char *s2);

#endif