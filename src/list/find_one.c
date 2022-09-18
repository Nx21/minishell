/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 22:08:02 by nhanafi           #+#    #+#             */
/*   Updated: 2022/09/18 22:08:55 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

char	*find_one(t_data *data, char *key)
{
	t_list	*head;

	head = data->l_env;
	if (!ft_strcmp("?", key))
		return (ft_strdup(data->state));
	while (head)
	{
		if (ft_strcmp(head->key, key) == 0)
			return (ft_strdup(head->value));
		head = head->next;
	}
	return (ft_strdup(""));
}
