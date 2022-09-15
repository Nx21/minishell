/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 21:02:51 by nhanafi           #+#    #+#             */
/*   Updated: 2022/09/14 22:23:19 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	ft_swap(char **str1, char **str2)
{
	char	*swap;

	swap = *str1;
	*str1 = *str2;
	*str2 = swap;
}

t_list *list_sort(t_list *head)
{
	t_list	*node1;
	int		change;

	change = 1;
	while (change)
	{
		change = 0;
		node1 = head;
		while (node1->next)
		{
			if (ft_strcmp(node1->key, node1->next->key) > 0)
			{
				ft_swap(&node1->key, &node1->next->key);
				ft_swap(&node1->value, &node1->next->value);
				change = 1;
			}
			node1 = node1->next;
		}
	}
	return head;
}

void	ft_printsort(t_list *head)
{
	head = list_sort(head);
	while (head)
	{
		printf("declare -x %s", head->key);
		if (head->value)
			printf("=\"%s\"", head->value);
		printf("\n");
		head = head->next;
	}
}