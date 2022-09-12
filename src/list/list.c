/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaanit <rjaanit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 02:33:07 by nhanafi           #+#    #+#             */
/*   Updated: 2022/09/11 14:17:42 by rjaanit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"


t_list	*add_one(t_list *head, t_list *list)
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
		if(!ft_strcmp(node->key, list->key))
		{
			free(node->value);
			node->value = list->value;
			free(list);
			return head;
		}
		node = node->next;
	}
	if(!ft_strcmp(node->key, list->key))
	{
		free(node->value);
		node->value = list->value;
		free(list);
		return head;
	}
	node->next = list;
	return head;
}

t_list *new_list(char *key, char *val)
{
	t_list *node;

	node = malloc(sizeof(t_list));
	node->key = key;
	node->value = val;
	node->next = NULL;
	return node;
}

t_list *env_list(char **str)
{
    t_list *list;
    int     i = 0;

    while((*str)[i] != '=')
        i++;
	list = new_list(ft_substr(*str, 0, i), ft_strdup(*str + i + 1));
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

char	*find_one(t_data *data, char *key)
{
	t_list *head;

	head = data->l_env;
	if(!ft_strcmp("?", key))
	{
		return ft_strdup(data->state);
	}
	while(head)
	{
		if(ft_strcmp(head->key, key) == 0)
			return ft_strdup(head->value);
		head = head->next;
	}
	return ft_strdup("");
}
