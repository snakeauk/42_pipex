/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 21:25:46 by kinamura          #+#    #+#             */
/*   Updated: 2024/09/25 23:27:50 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

char	*ft_get_path(char *cmd, char **envp)
{
	char	**env_path;
	char	*cmd_path;
	char	*path;
	int		index;

	index = 0;
	index = 0;
	while (envp[index] && ft_strnstr(envp[index], "PATH", 4) == 0)
		index++;
	if (!envp[index])
		return (NULL);
	env_path = ft_split(envp[index] + 5, ':');
	index = 0;
	while (env_path[index])
	{
		path = ft_strjoin(env_path[index], "/");
		cmd_path = ft_strjoin(path, cmd);
		free(path);
		if (ft_access(cmd_path) == 0)
		{
			ft_array_free(env_path);
			return (cmd_path);
		}
		free(cmd_path);
		index++;
	}
	ft_array_free(env_path);
	return (NULL);
}
