/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 02:33:07 by nhanafi           #+#    #+#             */
/*   Updated: 2022/08/27 02:34:21 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

t_list *env_list_sorted(t_list *head ,char **str)
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
	head = add_one_sort(head, list);
    if(*(str + 1))
        return env_list(head, str + 1);
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
        list->next = env_list1(str + 1);
    return list;
}