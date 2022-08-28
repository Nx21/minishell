/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 03:56:28 by nhanafi           #+#    #+#             */
/*   Updated: 2022/08/29 00:56:50 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_pipe(t_node *node, t_data *data)
{
    int fd[2];
    int pid[2];
    int state = 0;

    if (pipe(fd) < 0)
    {
        perror("minishell: ");
        return (1);
    }
    pid[1] = fork();
    if(pid[1] == 0)
    {
        
        dup2(fd[0],0);
        close(fd[1]);
        ft_putstr_fd()
    }
    pid[0] = fork();
    // if(pid[0] < 0)
    // {
    //     perror("minishell: ");
    //     return (1);
    // }
    if(pid[0] == 0)
    {
        dup2(fd[1],1);
        close(fd[0]);
        excu_ast(node->left, data);
        exit(0);        
    }
    wait(&pid[0]);
    wait(&pid[1]);
    close(fd[0]);
    close(fd[1]);
    return 1;
}

