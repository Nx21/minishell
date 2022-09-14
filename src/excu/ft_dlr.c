/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaanit <rjaanit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 09:18:34 by rjaanit           #+#    #+#             */
/*   Updated: 2022/09/14 09:18:35 by rjaanit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int error()
{
     perror("minishell:");
        return (1);
}

static void	ft_child1(int *fd1,t_data *data, t_node *node,int back_fd)
{
     if (dup2( fd1[ 0 ] , STDIN_FILENO ) < 0) 
                error();
        int state = 0;
           close( fd1[ 0 ] );
            close( fd1[ 1 ] );
            state = excu_ast(node->left, data);
            dup2(back_fd,STDIN_FILENO);
}

static void	ft_child2(int *fd1, t_node *node)
{
    if (dup2( fd1[ 1 ] , 1 ) < 0) 
        error();
    close( fd1[ 0 ] );
    close( fd1[ 1 ] );
    if( node->right->list && node->right->list->str)
        printf("%s", node->right->list->str);
        exit(0);
}

int     ft_dlr(t_node *node, t_data *data)
{
    int pid;
    int state = 0;

    pid = fork();
    if ( pid == 0 ) {
        int fd1[ 2 ];
        pipe( fd1 );
        int back_fd = dup(STDIN_FILENO);
        if ( (pid = fork()) > 0 ) 
            ft_child1(fd1,data,node,back_fd);
        else if ( pid == 0 ) 
            ft_child2(fd1,node);
        exit(state);
    }
    waitpid(pid, &state, 0);
    return 1;
}