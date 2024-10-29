/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 02:51:35 by kinamura          #+#    #+#             */
/*   Updated: 2024/10/30 03:20:33 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

void	ft_free_array3(void ***array)
{
	size_t	size;
	size_t	index;

	size = 0;
	if (!array)
		return ;
	while (array[size] != NULL)
	{
		index = 0;
		while (array[size][index] != NULL)
		{
			free(array[size][index]);
			index++;
		}
		free(array[size]);
		size++;
	}
	free(array);
}

void	ft_free_array2(void **array)
{
	size_t	index;

	index = 0;
	if (!array)
		return ;
	while (array[index] != NULL)
	{
		free(array[index]);
		index++;
	}
	free(array);
}

void	ft_wait_free_exit(char ***cmds, int exit_status)
{
	int	temp;

	temp = errno;
	while (wait(NULL) != -1)
		;
	errno = temp;
	if (cmds)
		ft_free_array3((void ***)cmds);
	exit(exit_status);
}

void	ft_exit_message(char *message)
{
	perror(message);
	exit(EXIT_FAILURE);
}
