/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaanit <rjaanit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 23:21:19 by rjaanit           #+#    #+#             */
/*   Updated: 2022/09/15 00:21:22 by rjaanit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_lr(t_node *node, t_data *data)
{
	int		status;
	int		back_fd;
	int		fd;

	(void)data;
	fd = open(node->right->list->str, O_RDONLY, 0777); // u don't need to open it for writing
	if (fd < 0)
	{
		ft_putstr_fd("minishell: ", 2);
		perror(node->right->list->str);
		
		return (1);
	}
	back_fd = dup(STDIN_FILENO);
	dup2(fd, STDIN_FILENO);
	close(fd);
	status = excu_ast(node->left, data);
	dup2(back_fd, STDIN_FILENO);
	return (status);
}
