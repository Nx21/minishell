/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 03:56:28 by nhanafi           #+#    #+#             */
/*   Updated: 2022/09/16 13:26:40 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_child1(int *fd1, t_data *data, t_node *node)
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
	return (state);
}

static int	ft_parent(int *fd1, t_data *data, t_node *node)
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
	return (state);
}

int	ft_pipe(t_node *node, t_data *data)
{
	int		pid[2];
	int		state;
	int		fd1[2];
	int		i = -1;

	state = 0;
	pipe(fd1);
	pid[0] = fork();
	if (pid[0] == 0)
		state = ft_child1(fd1, data, node);
	pid[1] = fork();
	if (pid[1] == 0)
		ft_parent(fd1, data, node);
	close(fd1[0]);
	close(fd1[1]);
	while(++i < 2)
		waitpid(pid[i], &state, 0);
	// exit(state);
	// waitpid(pid, &state, 0);
	return (WIFEXITED(state));
}
