/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 01:23:53 by nhanafi           #+#    #+#             */
/*   Updated: 2022/09/17 22:38:57 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_data	*get_data(char **envp)
{
	t_data		*data;

	data = malloc(sizeof(t_data));
	data->env = envp;
	data->state = ft_strdup("0");
	data->l_env = env_list(envp);
	data->last = NULL;
	return (data);
}

void	get_state(t_data *data, int a)
{
	char	*st;

	st = ft_itoa(a);
	free(data->state);
	data->state = st;
}

void	ft_loop(t_data *data, char *buf)
{
	t_node	*head;

	g_global = 1;
	buf = ft_parcing(buf);
	if (buf && g_global)
	{
		add_history(buf);
		head = ft_ast_lev1(buf);
		g_global= 2;
		get_state(data, excu_ast(head, data));
		free_ast(head);
	}
	if (buf)
		free(buf);
	else
		get_state(data, 258);
}

void	ft_signal(void)
{
	rl_catch_signals = 0;
	signal(SIGINT, handler);
	signal(SIGQUIT, handler);
}

int	main(int argc, char **argv, char **envp)
{
	char	*buf;
	int		back_fd;
	t_data	*data;

	(void)argc;
	(void)argv;
	ft_signal();
	back_fd = dup(STDIN_FILENO);
	data = get_data(envp);
	while (1)
	{
		dup2(back_fd, STDIN_FILENO);
		g_global = 0;
		buf = readline("minishell-1.0$ ");
		if (!buf)
			break ;
		ft_loop(data, buf);
	}
	rl_clear_history();
	exit(0);
}
