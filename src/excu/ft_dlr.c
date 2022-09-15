/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 09:18:34 by rjaanit           #+#    #+#             */
/*   Updated: 2022/09/15 22:52:09 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	error(void)
{
	perror("minishell:");
	return (1);
}

static void	ft_child1(int *fd1, t_data *data, t_node *node, int back_fd)
{
	int		state;

	state = 0;
	if (dup2(fd1[0], STDIN_FILENO) < 0)
		error();
	close(fd1[0]);
	close(fd1[1]);
	state = excu_ast(node->left, data);
	dup2(back_fd, STDIN_FILENO);
}

static void	ft_child2(int *fd1, t_node *node, t_data *data)
{
	char	**str;

	if (dup2(fd1[1], 1) < 0)
		error();
	close(fd1[0]);
	close(fd1[1]);
	if (node->right->list && node->right->list->str)
	{
		str = list_to_arr(node->right->list, data);
		printf("%s", str[0]);
	}
	exit(0);
}

int	ft_dlr(t_node *node, t_data *data)
{
	int		pid;
	int		state;
	int		fd1[2];
	int		back_fd;

	state = 0;
	back_fd = dup(STDIN_FILENO);
	pid = fork();
	if (pid == 0)
	{
		pipe(fd1);
		pid = fork();
		if (pid > 0)
			ft_child1(fd1, data, node, back_fd);
		else if (pid == 0)
			ft_child2(fd1, node, data);
		exit(state);
	}
	waitpid(pid, &state, 0);
	return (1);
}
