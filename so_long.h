#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# define FAILED 0
# define SUCCESS 1

// output:
void    print_error(char *s);

// parsing:
void	check_map(char *file_name);

#endif