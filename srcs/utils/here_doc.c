#include "utils.h"

int	is_here_doc(char **argv)
{
	return (ft_strncmp(argv[1], "here_doc", 8) == 0
		&& ft_strlen(argv[1]) == 8);
}