/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_join.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 01:06:44 by nhanafi           #+#    #+#             */
/*   Updated: 2022/09/02 01:04:25 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

char    *list_join(t_var  *list)
{
	char *s;
	t_var	*lst;

	s = NULL;
	lst = list;
	while(lst)
	{
		s = ft_join(s, lst->str);
		lst = lst->next;
	}
	while(list)
	{
		lst = list;
		list = list->next;
		free(lst->str);
		free(lst);
	}
	return s;
}