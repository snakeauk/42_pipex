/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 22:04:46 by kinamura          #+#    #+#             */
/*   Updated: 2024/09/03 22:10:48 by kinamura         ###   ########.fr       */
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
        ft_error();
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
        index = 2;
        outfile = ft_open_file(argv[argc - 1], 1);
        infile = ft_open_file(argv[1], 2);
        dup2(infile, STDIN_FILENO);
    }
    while (index < argc - 2)
    {
        ft_child_process(argv[index], envp);
        index++;
    }
    dup2(outfile, STDOUT_FILENO);
    ft_execute(argv[argc - 2], envp);
}
