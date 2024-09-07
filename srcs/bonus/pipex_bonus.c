/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 22:04:46 by kinamura          #+#    #+#             */
/*   Updated: 2024/09/07 13:45:55 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int main(int argc, char **argv, char **envp)
{
    int index;
    int infile;
    int outfile;

    if (argc <= 4)
    {
        ft_error("");
        return (0);
    }
    if (ft_strncmp(argv[1], "here_doc", 8) == 0)
    {
        index = 3;
        ft_here_doc(argv[2], argc);
        outfile = ft_open_file(argv[argc - 1], 0);
    }
    else
    {
        infile = ft_open_file(argv[1], 2);
        dup2(infile, STDIN_FILENO);
        index = 2;
        outfile = ft_open_file(argv[argc - 1], 1);
    }
    while (index < argc - 2)
    {
        ft_process(argv[index], envp);
        index++;
    }
	if (dup2(outfile, STDOUT_FILENO) == -1)
		ft_error("");
    ft_execute(argv[argc - 2], envp);
    return (0);
}
