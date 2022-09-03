/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 00:06:14 by nhanafi           #+#    #+#             */
/*   Updated: 2022/09/03 10:10:24 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char    **get_path(char *s)
{
    char **paths;

    paths = ft_split(s,':');
    return(paths);
}
char		*get_command(char **paths, char *command)
{
	char	*join_path;
	char	*get;
	int		res;

    if(ft_instr(command, '/') >= 0)
        return command;
	while(*paths)
	{
		join_path = ft_join(*paths,"/");
		get = ft_join(join_path,command);
		res = access(get, X_OK);
		if(!res)
			break;
		// free(get);
		paths++;
	}
	if(*paths == NULL)
		return(0);
	return(get);
}

int exe(char **str, t_data *data)
{
    char **s;
    int pid;
    int state = 0;

    pid = fork();
    if(pid == 0)
    {
        s = get_path(getenv("PATH"));
        state = execve(get_command(s, *str), str, data->env);
        ft_putstr_fd(str[0], 2);
        ft_putstr_fd(": command not found\n", 2);
        free(s);
        exit(state);
    }
    waitpid(pid,&state,0);
    return (state);
}

int ft_word(t_node *node, t_data *data)
{
	char **str;
    int i;
    int state;

	str = list_to_arr(node->list, data);
	free(node);
    state = exe(str, data);
    i = 0;
    while (str[i])
    {
       free(str[i]);
       i++;
    }
    free(str);
    return state;
}