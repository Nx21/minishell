/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaanit <rjaanit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 10:57:18 by nhanafi           #+#    #+#             */
/*   Updated: 2022/09/14 17:00:08 by rjaanit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exe_word(char **str, t_data *data)
{
	if (!ft_strcmp(str[0], "cd"))
		return (ft_cd(str, data));
	else if (!ft_strcmp(str[0], "pwd"))
		return (ft_pwd(data));
	else if (!ft_strcmp(str[0], "echo"))
		return (ft_echo(str));
	else if (!ft_strcmp(str[0], "exit"))
		return (ft_exit(str));
	else if (!ft_strcmp(str[0], "env"))
		return (ft_env(str, data));
	else if (!ft_strcmp(str[0], "unset"))
		return (ft_unset(str, data));
	else if (!ft_strcmp(str[0], "export"))
		return (ft_export(str, data));
	return (exe(str, data));
}

int	ft_word(t_node *node, t_data *data)
{
	char	**str;
	int		i;
	int		state;

	str = list_to_arr(node->list, data);
	node->list = NULL;
	state = exe_word(str, data);
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (state);
}
