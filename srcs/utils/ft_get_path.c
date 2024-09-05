/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 21:25:46 by kinamura          #+#    #+#             */
/*   Updated: 2024/09/03 21:59:14 by kinamura         ###   ########.fr       */
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
	paths = ft_split(&envp[index + 5], ':');
	index = 0;
	while (paths[index])
	{
		part_path = ft_strjoin(paths[index], "/");
		path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		index++;
	}
	ft_array_free(paths);
	return (NULL);
}
