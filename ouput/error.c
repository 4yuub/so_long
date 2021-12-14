#include "../so_long.h"

void	print_error(char *s)
{
	while (*s)
		write(2, s++, 1);
}
