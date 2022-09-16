/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_one.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 22:50:48 by nhanafi           #+#    #+#             */
/*   Updated: 2022/09/16 00:49:28 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	append_node(t_list *node, char *key, char *value)
{
	node->value = ft_join(node->value, value);
	free(value);
	free(key);
}

void	chage_node(t_list *node, t_list *list)
{
	if (list->value)
	{
		free(node->value);
		node->value = list->value;
	}
	free(list->key);
	free(list);
}

t_list	*append_one(t_list *head, char *key, char *value)
{
	t_list	*node;

	if (!head)
	{
		node = new_list(key, value);
		return (node);
	}
	node = head;
	while (node->next)
	{
		if (!ft_strcmp(node->key, key))
		{
			append_node(node, key, value);
			return (head);
		}
		node = node->next;
	}
	if (!ft_strcmp(node->key, key))
	{
		append_node(node, key, value);
		return (head);
	}
	node->next = new_list(key, value);
	return (head);
}

t_list	*add_one(t_list *head, t_list *list)
{
	t_list	*node;

	if (!head)
		return (list);
	node = head;
	while (node->next)
	{
		if (!ft_strcmp(node->key, list->key))
		{
			chage_node(node, list);
			return (head);
		}
		node = node->next;
	}
	if (!ft_strcmp(node->key, list->key))
	{
		chage_node(node, list);
		return (head);
	}
	node->next = list;
	return (head);
}
