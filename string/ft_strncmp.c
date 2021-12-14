int	ft_strncmp( char *s1, char *s2, int n)
{
	int	i;

	i = -1;
	while (++i < n && (s1[i] || s2[i]))
		if (s1[i] != s2[i])
			return (0);
	return (1);
} 