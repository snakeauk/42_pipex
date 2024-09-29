#include "ft_utils.h"

void	ft_exit(int status, char *message)
{
	ft_dprintf(STDERR_FILENO, message);
	ft_dprintf(STDERR_FILENO, "\n");
	exit(status);
}
