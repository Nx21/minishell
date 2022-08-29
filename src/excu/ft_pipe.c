/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 03:56:28 by nhanafi           #+#    #+#             */
/*   Updated: 2022/08/29 01:45:43 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_pipe(t_node *node, t_data *data)
{
   
    int pid;

    pid = fork();
    (void) data;
    (void) node;

    if ( pid == 0 ) {
        int fd1[ 2 ];
        pipe( fd1 );

        if ( (pid = fork()) > 0 ) {
            if (dup2( fd1[ 0 ] , 0 ) < 0) {
                perror("minishell:");
                exit(0);
            }
            close( fd1[ 0 ] );
            close( fd1[ 1 ] ); // important; see below
            // Note: /usr/bin, not /bin
            excu_ast(node->right, data);
        }
        else if ( pid == 0 ) {
            if (dup2( fd1[ 1 ] , 1 ) < 0) {
				perror("minishell:");
                exit(0);
            }
            close( fd1[ 0 ] );
            close( fd1[ 1 ] );
            excu_ast(node->left, data);
        }
        exit(0);
    }
    wait(0);
    // if(pid[0] < 0)
    // {
    //     perror("minishell: ");
    //     return (1);
    // }
    // if(pid[0] == 0)
    // {
    //     dup2(fd[1],1);
    //     close(fd[0]);
    //     ft_putstr_fd("ls", fd[1]);
    //     exit(0);        
    // }
    // if(pid[1] == 0)
    // {
    //     dup2(fd[0],0);
    //     // close(fd[0]);
    //     // close(fd[1]);
    //     excu_ast(node->right, data);
    //     exit(0);
    // }
    // waitpid(pid[0], NULL,0);
    // waitpid(pid[1], NULL,0);
    // close(fd[0]);
    // close(fd[1]);
    return 1;
}

