/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 03:56:28 by nhanafi           #+#    #+#             */
/*   Updated: 2022/09/18 21:59:47 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_rchild(int *fd1, t_data *data, t_node *node)
{
	int		state;

	state = 0;
	if (dup2(fd1[0], STDIN_FILENO) < 0)
	{
		perror("minishell");
		exit(1);
	}
	close(fd1[0]);
	close(fd1[1]);
	state = excu_ast(node->right, data);
	exit(state);
}

static int	ft_lchild(int *fd1, t_data *data, t_node *node)
{
	int		state;

	state = 0;
	if (dup2(fd1[1], STDOUT_FILENO) < 0)
	{
		perror("minishell");
		exit(1);
	}
	close(fd1[0]);
	close(fd1[1]);
	state = excu_ast(node->left, data);
	exit(state);
}

int	ft_pipe(t_node *node, t_data *data)
{
	int		pid;
	int		state;
	int		fd1[2];

	pipe(fd1);
	pid = fork();
	if (pid == 0)
		ft_lchild(fd1, data, node);
	pid = fork();
	if (pid == 0)
		ft_rchild(fd1, data, node);
	close(fd1[0]);
	close(fd1[1]);
	waitpid(pid, &state, 0);
	wait(0);
	return (WEXITSTATUS(state));
}
