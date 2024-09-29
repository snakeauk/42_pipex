#include "ft_utils.h"

int ft_access(char *filepath)
{
    if (access(filepath, F_OK) == 0)
    {
        if (access(filepath, X_OK) != 0)
            ft_dprintf(STDERR_FILENO, "Error: permission denied\n");
        else if (access(filepath, X_OK) == 0)
            return (0);
        return (-1);
    }
    return (-1);
}