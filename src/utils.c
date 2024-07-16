#include "cub3d.h"

void	error(char *error_msg)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(error_msg, 2);
	exit(EXIT_FAILURE);
}
