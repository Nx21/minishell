/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaanit <rjaanit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 03:56:28 by nhanafi           #+#    #+#             */
/*   Updated: 2022/09/09 23:36:12 by rjaanit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_child1(int *fd1, t_data *data, t_node *node)
{
	int		state;

	state = 0;
	if (dup2(fd1[0], STDIN_FILENO) < 0)
	{
		perror("minishell:");
		exit(1);
	}
	close(fd1[0]);
	close(fd1[1]);
	state = excu_ast(node->right, data);
}

static void	ft_parent(int *fd1, t_data *data, t_node *node)
{
	int		state;

	state = 0;
	if (dup2(fd1[1], STDOUT_FILENO) < 0)
	{
		perror("minishell:");
		exit(0);
	}
	close(fd1[0]);
	close(fd1[1]);
	state = excu_ast(node->left, data);
}

int	ft_pipe(t_node *node, t_data *data)
{
	int		pid;
	int		state;
	int		fd1[2];

	state = 0;
	pid = fork();
	if (pid == 0)
	{
		pipe(fd1);
		pid = fork();
		if (pid > 0)
			ft_child1(fd1, data, node);
		else if (pid == 0)
			ft_parent(fd1, data, node);
		exit(state);
	}
	waitpid(pid, &state, 0);
	return (state);
}