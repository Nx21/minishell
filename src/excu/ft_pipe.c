/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 03:56:28 by nhanafi           #+#    #+#             */
/*   Updated: 2022/09/03 09:53:34 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_pipe(t_node *node, t_data *data)
{
    int pid;
    int state = 0;

    pid = fork();
    if ( pid == 0 ) {
        int fd1[2];
        pipe( fd1 );
        if ( (pid = fork()) > STDIN_FILENO) {
            if (dup2( fd1[ 0 ] , STDIN_FILENO) < 0)
            {
                perror("minishell:");
                exit(1);
            }
            close(fd1[0]);
            close(fd1[1]);
            state = excu_ast(node->right, data);
        }
        else if ( pid == 0 ) 
        {
            if (dup2( fd1[ 1 ] , STDOUT_FILENO) < 0) 
            {
				perror("minishell:");
                exit(0);
            }
            close(fd1[0]);
            close(fd1[1]);
            state = excu_ast(node->left, data);
        }
        exit(state);
    }
    waitpid(pid, &state, 0);
    free(node);
    return state;
}

