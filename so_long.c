#include "so_long.h"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		print_error("Error\nInvalide Args\n");
		return (0);
	}
	check_map(av[1]);
}
