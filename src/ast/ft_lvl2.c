/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lvl2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaanit <rjaanit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 23:52:44 by nhanafi           #+#    #+#             */
/*   Updated: 2022/09/14 18:07:06 by rjaanit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	find_lev2(t_token *token, char *str)
{
	const char	*lev[] = {"|"};
	int			max;
	int			idx;
	int			i;

	max = -1;
	i = 0;
	while (i < 1)
	{
		idx = ft_get_last_ind(str, (char *)lev[i]);
		if (idx > max)
		{
			max = idx;
			*token = i + 3;
		}
		i++;
	}
	return (max);
}

t_node	*ft_ast_lev2(char *buf)
{	
	int		len;
	t_node	*node;
	t_token	token;

	if (!buf || !g_global)
		return (NULL);
	len = find_lev2(&token, buf);
	if (len > 0)
	{
		buf[len] = 0;
		node = add_node(NULL, token);
		node->left = ft_ast_lev2(buf);
		node->right = ft_ast_lev3(buf + len + 1);
		return (node);
	}
	return (ft_ast_lev3(buf));
}
