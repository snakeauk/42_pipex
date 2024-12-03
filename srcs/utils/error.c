#include "utils.h"

void	ft_error_exit(int status, int err_message);

void	ft_error_exit(int status, int err_message)
{
	errno = err_message;
	perror("Error");
	exit(status);
}
