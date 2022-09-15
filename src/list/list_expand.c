/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_expand.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 01:18:32 by nhanafi           #+#    #+#             */
/*   Updated: 2022/09/15 23:32:02 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"


t_var *list_expand_wc(t_var *list)
{
	t_var *next;
	t_var *node = NULL;

	if(!list)
		return NULL;
	next = list->next;
	list->next = NULL;
	if(ft_get_last_ind(list->str, "*") >= 0)
	{
		node = wc_handler(list->str, NULL);	
		if(node)
		{
			free(list->str);
			free(list);
			list = node;
		}
	}
	next = list_expand_wc(next);
	list_append(list, next);
	return list;
}

t_var	*list_expand(t_var *list, t_data *data)
{
	list = list_expand_var(list, data);
	list = list_expand_wc(list);
	list_expand_q(list);
	return list;
}


char **list_to_arr(t_var *list, t_data *data)
{
	char	**str;
	t_var	*node;
	int		i;
	
	list = list_expand(list, data);
	node = list;
	i = 0;
	while (node)
	{
		i++;
		node = node->next;
	}
	str = malloc(i * sizeof(char *) + 1);
	node = list;
	i = 0;
	while (node)
	{
		str[i] = node->str;
		list = node;
		node = node->next;
		free(list);
		i++;
	}
	str[i] = NULL;
	return str;
}