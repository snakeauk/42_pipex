#include "ft_utils.h"

void ft_int_array_free(int **array)
{
    int index;

    index = 0;
    while (array[index])
    {
        free(array[index]);
        index++;
    }
    free(array);
}

void	ft_char_array_free(char **array)
{
	int	index;

	index = 0;
	while (array[index])
	{
		free(array[index]);
		index++;
	}
	free(array);
}
