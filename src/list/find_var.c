/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_var.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 00:31:29 by nhanafi           #+#    #+#             */
/*   Updated: 2022/09/16 00:45:54 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

char	*var_alloc(char *var, char c)
{
	int	len;
	int	dq;
	int	sq;

	len = 0;
	dq = 0;
	sq = 0;
	while (var[len])
	{
		if (var[len] == '\'')
			sq++;
		if (var[len] == '\"')
			dq++;
		len++;
	}
	if (c)
		return (ft_calloc(sizeof(char), len + 4 * dq + 1));
	return (ft_calloc(sizeof(char), len + 2 * dq + 2 * sq + 1));
}

char	*find_var_dq(char *var, char c)
{
	int		i;
	int		j;
	char	*dst;

	dst = var_alloc(var, c);
	i = 0;
	j = 0;
	while (var[i])
	{
		if (c && var[i] == '\"')
		{
			ft_strcat(dst, (char *)"\"\'\"\'\"");
			j += 5;
		}
		else
			dst[j++] = var[i];
		i++;
	}
	return (dst);
}

char	*find_var_wq(char *var, char c)
{
	int		i;
	int		j;
	char	*dst;

	dst = var_alloc(var, c);
	i = 0;
	j = 0;
	while (var[i])
	{
		if (!c && var[i] == '\"')
		{
			ft_strcat(dst, (char *)"\'\"\'");
			j += 3;
		}
		else if (!c && var[i] == '\'')
		{
			ft_strcat(dst, (char *)"\"\'\"");
			j += 3;
		}
		else
			dst[j++] = var[i];
		i++;
	}
	return (dst);
}

char	*find_var(char *str, t_data *data, char c)
{
	char	*dst;
	char	*var;

	var = find_one(data, str);
	if (c)
		dst = find_var_dq(var, c);
	else
		dst = find_var_wq(var, c);
	free(str);
	free(var);
	return (dst);
}
