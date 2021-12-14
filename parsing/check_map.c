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
	check_file_name(file_name);
}
