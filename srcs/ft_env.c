/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:38:12 by kinamura          #+#    #+#             */
/*   Updated: 2024/10/14 11:38:14 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

char	**ft_env(char **envp)
{
	char	**path;
	int		index;

	index = 0;
	while (envp[index] && ft_strncmp(envp[index], "PATH=", 5) != 0)
		index++;
	if (!envp[index])
		return (NULL);
	path = ft_split(envp[index] + 5, ':');
	return (path);
}
