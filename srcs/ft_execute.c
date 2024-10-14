/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:38:15 by kinamura          #+#    #+#             */
/*   Updated: 2024/10/14 11:43:26 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

void	ft_execute(char *command, char **env)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(command, ' ');
	if (!cmd || !cmd[0])
	{
		ft_char_array_free(cmd);
		perror("Error: command parsing failed");
		exit(EXIT_FAILURE);
	}
	path = ft_get_path(cmd[0], env);
	if (!path)
	{
		fprintf(stderr, "%s: command not found\n", cmd[0]);
		ft_char_array_free(cmd);
		exit(EXIT_FAILURE);
	}
	if (execve(path, cmd, env) == -1)
	{
		perror("Error");
		ft_char_array_free(cmd);
		free(path);
		exit(128);
	}
}
