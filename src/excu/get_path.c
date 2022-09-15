/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaanit <rjaanit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 00:06:14 by nhanafi           #+#    #+#             */
/*   Updated: 2022/09/15 11:55:34 by rjaanit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
		// free(get);
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
		state = 1;
		s = get_path(find_one(data, "PATH"));
		execve(get_command(s, *str), str, data->env);
		// free(s);
		if (errno == EACCES)
			state = 126;
		else if (errno == ENOENT)
			state = 127;
		ft_putstr_fd(str[0], 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
		exit(state);	
	}
	waitpid(pid, &state, 0);
	if (WIFEXITED(state)) 
		return (WEXITSTATUS(state));
	else if (WIFSIGNALED(state))
		return (128 + WTERMSIG(state));
	return (1);
}
