/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 20:54:25 by kinamura          #+#    #+#             */
/*   Updated: 2024/09/03 00:34:22 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

void	ft_execute(char *input, char **envp)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(input, ' ');
	path = ft_get_path(cmd[0], envp);
	if (!path)
	{
		ft_array_free(cmd);
		ft_error();
	}
	if (execve(path, cmd, envp) == -1)
		ft_error();
}
