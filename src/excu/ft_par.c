/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_par.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 23:53:33 by nhanafi           #+#    #+#             */
/*   Updated: 2022/09/20 22:55:46 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_par(t_node *node, t_data *data)
{
	int	pid;
	int	state;

	pid = fork();
	if (pid == 0)
	{
		state = excu_ast(node->left, data);
		exit(state);
	}
	waitpid(pid, &state, 0);
	return (WEXITSTATUS(state));
}
