/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 13:29:23 by nhanafi           #+#    #+#             */
/*   Updated: 2022/08/13 23:20:02 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

t_node	*add_node(char *str, t_token token)
{
	t_node *node;

	node = (t_node *) malloc(sizeof(t_node));
	node->str = str;
	node->token = token;
	node->left = NULL;
	node->right = NULL;
	return node;
}