/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 00:06:14 by nhanafi           #+#    #+#             */
/*   Updated: 2022/09/09 14:25:30 by nhanafi          ###   ########.fr       */
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
        s = get_path(find_one(data, "PATH"));
        execve(get_command(s, *str), str, data->env);
        ft_putstr_fd(str[0], 2);
        ft_putstr_fd(": command not found\n", 2);
        free(s);
        exit(127);
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
    node->list = NULL;
    if(!ft_strcmp(str[0], "cd"))
        state = ft_cd(str, data);
    else if(!ft_strcmp(str[0], "pwd"))
        state = ft_pwd(data);
    else if(!ft_strcmp(str[0], "echo"))
        state = ft_echo(str);
    else if(!ft_strcmp(str[0], "exit"))
        state = ft_exit(str);
    else if(!ft_strcmp(str[0], "env"))
        state = ft_env(str, data);
    else if(!ft_strcmp(str[0], "unset"))
        state = ft_unset(str, data);
    else if(!ft_strcmp(str[0], "export"))
        state = ft_export(str, data);
    else
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