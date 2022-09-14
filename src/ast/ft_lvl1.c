/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lvl1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaanit <rjaanit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 23:52:41 by nhanafi           #+#    #+#             */
/*   Updated: 2022/09/14 14:12:05 by rjaanit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	find_lev1(t_token *token, char *str)
{
	const char	*lev[] = {"||", "&&"};
	int			max;
	int			idx;
	int			i;

	max = -1;
	i = 0;
	while (i < 2)
	{
		idx = ft_get_last_ind(str, (char *)lev[i]);
		if (idx > max)
		{
			max = idx;
			*token = i + 1;
		}
		i++;
	}
	return (max);
}

t_node	*ft_ast_lev1(char *buf)
{
	int		len;
	t_node	*node;
	t_token	token;

	if (!buf || !G_global)
		return (NULL);
	len = find_lev1(&token, buf);
	if (len > 0)
	{
		buf[len - 1] = 0;
		node = add_node(NULL, token);
		node->left = ft_ast_lev1(buf);
		node->right = ft_ast_lev2(buf + len + 1);
		return (node);
	}
	return (ft_ast_lev2(buf));
}
