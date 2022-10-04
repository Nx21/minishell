/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 19:04:29 by nhanafi           #+#    #+#             */
/*   Updated: 2022/10/03 20:21:09 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_key(char *str)
{
	int	i;

	i = 0;
	if (str[i] >= '0' && str[i] <= '9')
		return (0);
	while (str[i] && str[i] != '=' && str[i] != '+')
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (0);
		i++;
	}
	if (str[i] == '+' && str[i + 1] != '=')
		return (0);
	return (1);
}

int	ft_export_error(char *str)
{
	ft_putstr_fd("export: `", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\': not a valid identifier\n", 2);
	return (1);
}

int	add_tolist(char *str, t_data *data)
{
	int		len[3];

	len[0] = ft_get_first_ind(str, "+=");
	len[1] = ft_get_first_ind(str, "=");
	len[2] = ft_get_first_ind(str, "+");
	if (!check_key(str) || (len[2] >= 0 && \
		(len[2] < len[0] - 1 || (len[2] > len[1] && len[2] < len[1]))))
		return (ft_export_error(str));
	else if (len[0] >= 0 || len[1] >= 0)
	{
		if (len[0] >= 0 && len[0] <= len[1])
		{	
			data->l_env = append_one(data->l_env, \
			ft_substr(str, 0, len[0] - 1), ft_substr(str, len[0] + 1, \
			ft_strlen(str) - len[0] - 1));
		}
		else
			data->l_env = add_one(data->l_env, \
			new_list(ft_substr(str, 0, len[1]), \
			ft_substr(str, len[1] + 1, ft_strlen(str) - len[1] - 1)));
	}
	else
		data->l_env = add_one(data->l_env, new_list(ft_strdup(str), NULL));
	return (0);
}

int	ft_export(char **str, t_data *data)
{
	int		i;
	int		pid;
	int		state;

	if (str[1])
	{
		state = 0;
		i = 1;
		while (str[i])
		{
			state |= add_tolist(str[i], data);
			i++;
		}
		return (state);
	}
	pid = fork();
	if (pid == 0)
	{
		ft_printsort(data->l_env);
		exit(0);
	}
	dat
	wait(0);
	return (0);
}
