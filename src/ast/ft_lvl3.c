/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lvl3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 02:13:01 by nhanafi           #+#    #+#             */
/*   Updated: 2022/08/28 03:24:14 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

int	find_lev3(t_token *token, char *str)
{
	const char	*lev[] = {"<<", "<"};
	int			max;
	int			idx;
	int			i;
	
	max = -1;
	i = 0;
	while(i < 2)
	{
		idx = ft_get_last_ind(str, (char *)lev[i]);
		if(idx > max)
		{
			max = idx;
			*token = i + 6;
		}
		i++;
	}
	return max;
}

t_node *ft_ast_lev3(char *buf)
{	
	int len;
	t_node	*node;
	t_token token;
	
	if(!buf)
		return NULL;
	len = find_lev3(&token, buf);
	if(len > 0)
	{
		buf[len - (token == 6)] = 0;
		node = add_node(NULL, token);
		node->left = ft_ast_lev3(buf);
		if (token == DLR)
			node->right = ft_read_eof(buf + len + 1);
		else
			node->right = ft_cmd(buf + len + 1);
		return node;
	}
	return ft_cmd(buf);
}