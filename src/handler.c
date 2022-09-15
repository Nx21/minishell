/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 20:55:05 by nhanafi           #+#    #+#             */
/*   Updated: 2022/09/14 20:56:02 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handler(int num)
{
	int		fd[2];

	if (num == SIGQUIT)
		return ;
	if (!g_global)
	{
		printf("\n");
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
	else
	{
		g_global = 0;
		pipe(fd);
		dup2(fd[0], STDIN_FILENO);
		ft_putstr_fd("\n", fd[1]);
	}
}