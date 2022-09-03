/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 13:29:23 by nhanafi           #+#    #+#             */
/*   Updated: 2022/09/02 00:09:30 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"
#include "env.h"

t_node	*add_node(t_var *list, t_token token)
{
	t_node *node;

	node = (t_node *) malloc(sizeof(t_node));
	node->list = list;
	node->token = token;
	if(token == W && !list)
		node->token = 0;
	node->left = NULL;
	node->right = NULL;
	return node;
}