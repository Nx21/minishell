/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 02:33:07 by nhanafi           #+#    #+#             */
/*   Updated: 2022/09/18 22:08:31 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

t_list	*new_list(char *key, char *val)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	node->key = key;
	node->value = val;
	node->next = NULL;
	return (node);
}

void	check_shlvl(char **str, int i)
{
	char	*sub;
	char	*val;
	char	*nval;

	sub = ft_substr(*str, 0, i);
	if (ft_strcmp(sub, "SHLVL"))
	{
		free(sub);
		return ;
	}
	val = ft_strdup(*str + i + 1);
	*str = ft_join(sub, "=");
	nval = ft_itoa(ft_atoi(val) + 1);
	*str = ft_join(*str, nval);
	free(val);
	free(nval);
}

t_list	*env_list(char **str)
{
	t_list	*list;
	int		i;

	i = 0;
	if (!str || !*str)
		return (NULL);
	while ((*str)[i] != '=')
		i++;
	check_shlvl(str, i);
	list = new_list(ft_substr(*str, 0, i), ft_strdup(*str + i + 1));
	if (*(str + 1))
		list->next = env_list(str + 1);
	return (list);
}

void	del_list(t_list *node)
{
	free(node->key);
	free(node->value);
	free(node);
}

t_list	*del_one(t_list *head, char *str)
{
	t_list	*node;
	t_list	*next;

	node = head;
	if (node && !ft_strcmp(str, node->key))
	{
		head = node->next;
		del_list(node);
		return (head);
	}
	while (node && node->next)
	{
		if (!ft_strcmp(str, node->next->key))
		{
			next = node->next;
			node->next = next->next;
			del_list(next);
			break ;
		}
		node = node->next;
	}
	return (head);
}
