/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 00:47:21 by nhanafi           #+#    #+#             */
/*   Updated: 2022/09/16 00:48:50 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

char	*var_handler_v(char *str, char c, t_data *data)
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
		dst = find_var(ft_substr(str, 0, len), data, c);
	else
		dst = ft_strdup("$");
	if (str[len])
		tmp = var_handler(str + len, data, c);
	dst = ft_join(dst, tmp);
	return (free(tmp), dst);
}

char	*var_handler(char *str, t_data *data, char c)
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
		if (c == str[len])
			c = 0;
		else if (!c && (str[len] == '\'' || str[len] == '\"'))
			c = str[len];
		else if (c != '\'' && str[len] == '$')
			break ;
		len++;
	}
	dst = ft_substr(str, 0, len);
	if (str[len])
		tmp = var_handler_v(str + len + 1, c, data);
	dst = ft_join(dst, tmp);
	return (free(tmp), dst);
}

t_var	*list_expand_var(t_var *list, t_data *data)
{
	t_var	*lst;
	t_var	*next;
	char	*str;

	if (!list)
		return (NULL);
	next = list->next;
	str = var_handler(list->str, data, 0);
	lst = list_split(str);
	free(str);
	free(list->str);
	free(list);
	list = lst;
	next = list_expand_var(next, data);
	list_append(list, next);
	return (list);
}
