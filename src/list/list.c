/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 02:33:07 by nhanafi           #+#    #+#             */
/*   Updated: 2022/09/04 09:22:58 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

t_list	*add_one_sort(t_list *head, t_list *list)
{
	t_list *node;

	if(!head || ft_strcmp(head->key, list->key) > 0)
	{
		list->next = head;
		return list;
	}
	node = head;
	while(node->next)
	{
		if(ft_strcmp(node->next->key, list->key) > 0)
		{
			list->next = node->next;
			node->next = list;
			return head;
		}
		if(!ft_strcmp(node->key, list->key))
		{
			node->key = list->key;
			node->value = list->value;
			free(list);
			return head;
		}
		node = node->next;
	}
	node->next = list;
	return head;
}

t_list *env_list(char **str)
{
    t_list *list;
    int     i = 0;

    while((*str)[i] != '=')
        i++;
    list = malloc(sizeof(t_list));
    list->key = ft_substr(*str, 0, i);
    list->value = ft_strdup(*str + i + 1);
    list->tag = 1;
    list->next = NULL;
    if(*(str + 1))
        list->next = env_list(str + 1);
    return list;
}

void del_list(t_list *node)
{
	free(node->key);
	free(node->value);
	free(node);
}

t_list *del_one(t_list *head, char *str)
{
	t_list	*node;
	t_list	*next;

	node = head;
	if(node && !ft_strcmp(str, node->key))
	{
		head = node->next;
		del_list(node);
		return head;
	}
	while(node && node->next)
	{
		if(!ft_strcmp(str, node->next->key))
		{
			next = node->next;
			node->next = next->next;
			del_list(next);
			break;
		}
		node = node->next;
	}
	return head;	
}

char	*find_one(t_list *head, char *str)
{
	if(ft_strcmp("?", str) == 0)
		ft_strdup("1");
	while(head)
	{
		if(ft_strcmp(head->key, str) == 0)
			return ft_strdup(head->value);
		head = head->next;
	}
	return ft_strdup("");
}

