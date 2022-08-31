/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 23:21:19 by rjaanit           #+#    #+#             */
/*   Updated: 2022/08/31 02:21:05 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int     ft_lr(t_node *node, t_data *data)
{
    int back_fd;
    int status;
    (void) data;

    int fd = open(node->right->str[0], O_RDWR  , 0777);
    if(fd < 0)
    {
        perror("minishell: ");
        return 1;
    }
    back_fd = dup(STDIN_FILENO);
    dup2(fd,STDIN_FILENO);
    close(fd);
    status =  excu_ast(node->left, data);
    dup2(back_fd,STDIN_FILENO);
    return(status);
}
