/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_handler_dlr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 22:40:23 by nhanafi           #+#    #+#             */
/*   Updated: 2022/09/20 22:56:13 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*find_var_dlr(char *str, t_data *data)
{
	char	*var;

	var = find_one(data, str);
	if (!var)
		return (ft_strdup(""));
	return (var);
}

char	*var_handler_v_dlr(char *str, t_data *data)
{
	int		len;
	char	*dst;
	char	*tmp;
	int		b;

	len = 0;
	tmp = NULL;
	b = 0;
	if (str[len] && ((str[len] >= '0' && str[len] <= '9') || str[len] == '?'))
	{
		len++;
		b = 1;
	}
	while (!b && str[len] && (ft_isalnum(str[len]) || str[len] == '_'))
		len++;
	if (len)
		dst = find_var_dlr(ft_substr(str, 0, len), data);
	else
		dst = ft_strdup("$");
	if (str[len])
		tmp = var_handler_dlr(str + len, data);
	dst = ft_join(dst, tmp);
	return (free(tmp), dst);
}

char	*var_handler_dlr(char *str, t_data *data)
{
	int		len;
	char	*tmp;
	char	*dst;

	len = 0;
	dst = NULL;
	tmp = NULL;
	if (!str || !*str)
		return (NULL);
	while (str[len])
	{
		if (str[len] == '$')
			break ;
		len++;
	}
	dst = ft_substr(str, 0, len);
	if (str[len])
		tmp = var_handler_v_dlr(str + len + 1, data);
	dst = ft_join(dst, tmp);
	return (free(tmp), dst);
}
