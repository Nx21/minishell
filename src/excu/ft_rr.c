/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 21:40:11 by rjaanit           #+#    #+#             */
/*   Updated: 2022/09/03 09:51:29 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int     ft_rr(t_node *node, t_data *data)
{
    int status;
    int back_fd;
    (void) data;
    int fd = open(node->right->list->str,O_CREAT | O_RDWR | O_TRUNC , 0777);
    if(fd < 0)
    {
        perror("minishell");
        return 1;
    
    }
    back_fd = dup(STDOUT_FILENO);
    dup2(fd,STDOUT_FILENO);
    close(fd);
    status =  excu_ast(node->left, data);
    dup2(back_fd,STDOUT_FILENO);
    free(node);
    return(status);
}
