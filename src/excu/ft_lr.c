/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaanit <rjaanit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 23:21:19 by rjaanit           #+#    #+#             */
/*   Updated: 2022/09/14 15:36:18 by rjaanit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_lr(t_node *node, t_data *data)
{
	int		status;
	int		back_fd;
	int		fd;

	(void)data;
	fd = open(node->right->list->str, O_RDWR, 0777);
	if (fd < 0)
	{
		perror("minishell: ");
		return (1);
	}
	back_fd = dup(STDIN_FILENO);
	dup2(fd, STDIN_FILENO);
	close(fd);
	status = excu_ast(node->left, data);
	dup2(back_fd, STDIN_FILENO);
	return (status);
}
