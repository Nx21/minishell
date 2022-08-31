/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 03:56:28 by nhanafi           #+#    #+#             */
/*   Updated: 2022/08/31 02:19:08 by nhanafi          ###   ########.fr       */
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
    return 1;
}

