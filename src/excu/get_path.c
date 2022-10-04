/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 00:06:14 by nhanafi           #+#    #+#             */
/*   Updated: 2022/10/03 00:24:31 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	print_sig(int state)
{
	if (WIFEXITED(state))
		return (WEXITSTATUS(state));
	else if (WIFSIGNALED(state))
	{
		if (WTERMSIG(state) != SIGINT)
		{
			if (WTERMSIG(state) == SIGQUIT)
				printf("Quit: ");
			printf("%d", WTERMSIG(state));
		}	
		printf("\n");
		return (128 + WTERMSIG(state));
	}
	return (1);
}

static void	print_err(char *str)
{
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd("\n", 2);
}

char	**get_path(char *s)
{
	char	**paths;

	paths = ft_split(s, ':');
	return (paths);
}

char	*get_command(char **paths, char *command)
{
	char	*join_path;
	char	*get;
	int		res;

	if (ft_instr(command, '/') >= 0)
		return (command);
	while (*paths)
	{
		join_path = ft_join(*paths, "/");
		get = ft_join(join_path, command);
		res = access(get, X_OK);
		if (!res)
			break ;
		paths++;
	}
	if (*paths == NULL)
	{
		ft_putstr_fd(command, 2);
		ft_putstr_fd(": command not found !\n", 2);
		return (exit(127), NULL);
	}
	return (get);
}

int	exe(char **str, t_data *data)
{
	char	**s;
	int		pid;
	int		state;

	state = 0;
	pid = fork();
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		state = 1;
		s = get_path(find_one(data, "PATH"));
		execve(get_command(s, *str), str, data->env);
		if (errno == EACCES)
			state = 126;
		else if (errno == ENOENT)
			state = 127;
		print_err(str[0]);
		exit(state);
	}
	waitpid(pid, &state, 0);
	return (print_sig(state));
}
