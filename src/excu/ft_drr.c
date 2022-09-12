/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaanit <rjaanit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 04:55:00 by rjaanit           #+#    #+#             */
/*   Updated: 2022/09/09 23:50:16 by rjaanit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_drr(t_node *node, t_data *data)
{
	int		status;
	int		back_fd;
	int		fd;

	(void)data;
	fd = open(node->right->list->str, O_CREAT | O_RDWR | O_APPEND, 0777);
	status = 0;
	back_fd = dup(STDOUT_FILENO);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	status = excu_ast(node->left, data);
	dup2(back_fd, STDOUT_FILENO);
	return (status);
}
