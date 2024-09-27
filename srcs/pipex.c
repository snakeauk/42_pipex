/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 00:40:55 by kinamura          #+#    #+#             */
/*   Updated: 2024/09/26 02:28:25 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// int	main(int argc, char **argv, char **envp)
// {
// 	int		fd[2];

// 	if (argc != 5)
// 		ft_error("Error: Invalid number of arguments\n");
// 	if (pipe(fd) == -1)
// 		ft_error("Error: Failed to create pipe\n");
// 	ft_process(argc, argv, envp, fd);
// 	return (0);
// }


# define R 0
# define W 1


char	**ft_command(int argc, char **argv)
{
	char	**cmd;
	int		index;
	int		cmd_index;

	index = 2;
	cmd_index = 0;
	cmd = (char **)malloc(sizeof(char*) * (argc - 1));
	while(index < argc - 1)
		cmd[cmd_index++] = argv[index++];
	cmd[cmd_index] = NULL;
	return (cmd);
}

int main(int argc, char **argv, char **envp)
{
	int	ret;

	ret = 0;
    if (argc < 5)
        ft_error("Error: Invalid number of arguments");

    ft_pipex(argc, argv, envp);
    return (ret);
}

