/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 23:34:01 by nhanafi           #+#    #+#             */
/*   Updated: 2022/09/08 16:31:32 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <sys/stat.h>


char *ft_append_path(char *str, char *path)
{
	int	j;
	char *tmp;
	
	if(!ft_strcmp(str, "."))
	{
		free(str);
		return (path);
	}
	if(!ft_strcmp(str, ".."))
	{
		j = ft_strlen(path);
		while(path[j] != '/')
			j--;
		tmp = ft_substr(path, 0, j);
		free(path);
		return tmp;
	}
	path = ft_join(path,"/");
	path = ft_join(path, str);
	free(str);
	return path;
}


char *find_abs_path(char *str, char *path)
{
	char *tmp;
	int	i;

	if(!str || !str[0])
		return path;
	i = 0;
	while(str[i] && str[i] != '/')
		i++;
	tmp = ft_substr(str, 0, i);
	path = ft_append_path(tmp, path);
	return find_abs_path(str + i + 1, path);
}


int	ft_chdir(char *path, t_data *data)
{
	int ch;

	ch = chdir(path);
	printf("here");
    if (ch < 0)
	{
		free(path);
    	perror("minishell");
		return (1);
	}
	data->l_env = add_one(data->l_env, new_list(ft_strdup("OLDPWD")\
	, find_one(data, "PWD")));
	data->l_env = add_one(data->l_env, new_list(ft_strdup("PWD"), path));
	return (0);
}

char *check_dir(char **str, t_data *data)
{
	struct stat buf;
	char *path;

	if(!str[1])
		path = find_one(data, "HOME");
	else if (!ft_strcmp(str[1], "-"))
		path = find_one(data, "OLDPWD");
	else if(str[1][0] != '/')
		path = find_abs_path(str[1], find_one(data, "PWD"));
	else 
		path = find_abs_path(str[1], ft_strdup("/"));
	if(stat(path, &buf) < 0)
	{
		free(path);
		return NULL;
	}
	return path;
}


int	ft_cd(char **str, t_data *data)
{
	char *path;
	
	path = check_dir(str, data);
	printf("%s\n", path);
	if(!path && str[1] && !ft_strcmp(str[1], "."))
	{
		ft_putstr_fd("cd: error retrieving current directory:\
		\ngetcwd: cannot access parent directories: No such file or directory\n",2);
		return 1;
	}
	if(!path)
	{
		ft_putstr_fd("cd: ",2);
		ft_putstr_fd(str[1],2);
		ft_putstr_fd(": No such file or directory\n",2);
		return 1;
	}
	if(str[1] && !ft_strcmp(str[1], "-") && !ft_strcmp(path, ""))
		return 1 && ft_putstr_fd("cd: OLDPWD not set\n",2);
	return ft_chdir(path, data);		
}