/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 21:25:46 by kinamura          #+#    #+#             */
/*   Updated: 2024/09/20 00:06:34 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

char	*ft_get_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	char	*part_path;
	int		index;

	index = 0;
	while (ft_strnstr(envp[index], "PATH", 4) == 0)
		index++;
	paths = ft_split(envp[index] + 5, ':');
	index = -1;
	while (paths[++index])
	{
		part_path = ft_strjoin(paths[index], "/");
		path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (ft_access(path) == 0)
		{
			ft_array_free(paths);
			return (path);
		}
		free(path);
	}
	ft_array_free(paths);
	return (NULL);
}
