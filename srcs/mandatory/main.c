/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:38:03 by kinamura          #+#    #+#             */
/*   Updated: 2024/10/14 11:41:16 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		ret;
	char	**env;

	if (argc != 5)
		ft_exit(EXIT_FAILURE, "Error: Invalid number of arguments");
	env = ft_env(envp);
	if (!env)
		ft_exit(EXIT_FAILURE, "Error: PATH not found in environment variables");
	ret = ft_pipex(argc, argv, env);
	return (ret);
}
