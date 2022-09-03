/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_append.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 01:06:31 by nhanafi           #+#    #+#             */
/*   Updated: 2022/09/02 02:49:25 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

t_var *list_append(t_var *head, t_var	*var)
{
	t_var *node;

	if(!head)
		return var;
	node = head;
	while(node->next)
		node = node->next;
	node->next = var; 
	return head;
}