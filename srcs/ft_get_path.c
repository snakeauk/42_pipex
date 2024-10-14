/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:38:20 by kinamura          #+#    #+#             */
/*   Updated: 2024/10/14 11:42:59 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

char	*ft_get_path(char *cmd, char **env)
{
	char	*cmd_path;
	char	*path;
	int		index;

	index = 0;
	while (env[index])
	{
		path = ft_strjoin(env[index], "/");
		cmd_path = ft_strjoin(path, cmd);
		free(path);
		if (ft_access(cmd_path) == 0)
		{
			ft_char_array_free(env);
			return (cmd_path);
		}
		free(cmd_path);
		index++;
	}
	ft_char_array_free(env);
	return (NULL);
}
