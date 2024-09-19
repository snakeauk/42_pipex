/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 20:54:25 by kinamura          #+#    #+#             */
/*   Updated: 2024/09/20 00:10:30 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

void	ft_execute(char *input, char **envp)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(input, ' ');
	if (!cmd || !cmd[0])
	{
		ft_array_free(cmd);
		ft_error("Error: command parsing failed\n");
		exit(EXIT_FAILURE);
	}
	path = ft_get_path(cmd[0], envp);
	if (!path)
	{
		ft_array_free(cmd);
		ft_error("Error: command not found\n");
	}
	if (execve(path, cmd, envp) == -1)
	{
		perror("Error: permission denied");
		ft_array_free(cmd);
		free(path);
		exit(EXIT_FAILURE);
	}
	ft_array_free(cmd);
	free(path);
}