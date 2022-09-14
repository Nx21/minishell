/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lvl3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaanit <rjaanit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 02:13:01 by nhanafi           #+#    #+#             */
/*   Updated: 2022/09/14 14:16:21 by rjaanit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	find_lev3(t_token *token, char *str)
{
	const char	*lev[] = {"<<", ">>", "<", ">"};
	int			max;
	int			idx;
	int			i;

	max = -1;
	i = 0;
	while (i < 4)
	{
		idx = ft_get_first_ind(str, (char *)lev[i]);
		if (idx > max)
		{
			max = idx;
			*token = i + 4;
		}
		i++;
	}
	return (max);
}

int	ft_next_word(char *str)
{
	int		i;

	i = 0;
	while (str && str[i] && ft_instr("\t\n ", str[i]) >= 0)
		i++;
	while (str && str[i] && ft_instr("\t\n ", str[i]) < 0)
		i++;
	return (i);
}

t_node	*ft_ast_lev3(char *buf)
{	
	int		len;
	int		end_wd;
	t_node	*node;
	t_token	token;
	char	*right_str;

	if (!buf || !G_global)
		return (NULL);
	len = find_lev3(&token, buf);
	if (len >= 0)
	{
		node = add_node(NULL, token);
		end_wd = ft_next_word(buf + len + 1);
		right_str = ft_substr(buf + len + 1, 0, end_wd);
		ft_memset(buf + len - (token < LR), ' ', end_wd + 1 + (token < LR));
		if (token == DLR)
			node->right = ft_read_eof(right_str);
		else
			node->right = ft_cmd(right_str);
		node->left = ft_ast_lev3(buf);
		free(right_str);
		return (node);
	}
	return (ft_cmd(buf));
}
