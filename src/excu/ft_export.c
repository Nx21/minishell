/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 19:04:29 by nhanafi           #+#    #+#             */
/*   Updated: 2022/09/09 13:51:30 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


t_list	*append_one(t_list *head, char *key, char *value)
{
	t_list *node;

	if(!head || ft_strcmp(head->key, key) > 0)
	{
		node = new_list(key, value);
		node->next = head;
		return node;
	}
	node = head;
	while(node->next)
	{
		if(!ft_strcmp(node->key, key))
		{
			node->value = ft_join(node->value, value);
			free(value);
			free(key);
			return head;
		}
		node = node->next;
	}
	if(!ft_strcmp(node->key, key))
	{
		node->value = ft_join(node->value, value);
		free(value);
		free(key);
		return head;
	}
	node->next = new_list(key, value);
	return head;
}


void add_tolist(char *str, t_data *data)
{
	int len[3];

	len[0] = ft_get_first_ind(str, "+=");
	len[1] = ft_get_first_ind(str, "=");
	len[2] = ft_get_first_ind(str, "+");
	if(len[2] >= 0 && (len[2] < len[0] - 1 || (len[2] > len[1] && len[2] < len[1])))
	{
		ft_putstr_fd("export: `", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd("\': not a valid identifier\n", 2);
	}
	else if(len[0] >=0 || len[1] >= 0)
	{
		if(len[0] >= 0 && len[0] <= len[1])
		{	
			data->l_env = append_one(data->l_env, ft_substr(str, 0, len[0] - 1),\
			ft_substr(str, len[0] + 1, ft_strlen(str) - len[0] - 1));
		}
		else
			data->l_env = add_one(data->l_env, new_list(ft_substr(str, 0, len[1]),\
			ft_substr(str, len[1] + 1, ft_strlen(str) - len[1] - 1)));
	}
	else
		data->l_env = add_one(data->l_env, new_list(ft_strdup(str), NULL));
}

void ft_swap(char **str1, char **str2)
{
	char *swap;

	swap = *str1;
	*str1 = *str2;
	*str2 = swap;
}

void ft_printsort(t_list *head)
{
	t_list	*node1;
	int		change;

	change = 1;
	while(change)
	{
		change = 0;
		node1 = head;
		while(node1->next)
		{
			if(ft_strcmp(node1->key, node1->next->key) > 0)
			{
				ft_swap(&node1->key, &node1->next->key);
				ft_swap(&node1->value, &node1->next->value);
				change = 1;
			}
			node1 = node1->next;
		}
	}
	while (head)
    {
		printf("declare -x %s", head->key);
        if(head->value)
            printf("=\"%s\"", head->value);
		printf("\n");
        head = head->next;
    }	
}

int ft_export(char **str, t_data *data)
{
	int i;
	int pid;

	if(str[1])
	{
		i = 1;
		while(str[i])
		{
			add_tolist(str[i], data);
			i++;
		}
		return 0;
	}
	pid = fork();
	if(pid == 0)
	{
		ft_printsort(data->l_env);
		exit(0);
	}
	wait(0);
	return 0;
}