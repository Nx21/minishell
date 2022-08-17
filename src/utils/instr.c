/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 06:28:51 by nhanafi           #+#    #+#             */
/*   Updated: 2022/08/17 03:03:36 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_instr(char *str, char c)
{
	int	i;

	i = 0;
	while(str[i])
	{
		if(c == str[i])
			return i;
		i++;
	}
	return -1;
}

int	find_lev1(t_token *token, char *str)
{
	const char	*lev[] = {"||", "&&"};
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
			*token = i + 1;
		}
		i++;
	}
	return max;
}

int	find_lev2(t_token *token, char *str)
{
	const char	*lev[] = {"<<", ">>", "|", "<", ">"};
	int			max;
	int			idx;
	int			i;
	
	max = -1;
	i = 0;
	while(i < 5)
	{
		idx = ft_get_last_ind(str, (char *)lev[i]);
		if(idx > max)
		{
			max = idx;
			*token = i + 3;
		}
		i++;
	}
	return max;
}

int	ft_get_last_ind(char *str, char *to_find)
{
	int	i;
	int	j;
	char	c;

	i = ft_strlen(str) - 1;
	c = 0;
	while(str[i])
	{
		j = 0;
		if(!c && ft_instr("\"\'", str[i]) >= 0)
			c = str[i];
		else if(!c && ft_instr(")", str[i]) >= 0)
			c = str[i] - 1;
		else if(c == str[i])
			c = 0;
		while(!c && to_find[j] && str[i + j] == to_find[j])
			j++;
		if(!to_find[j])
			return i + j - 1;
		i--;
	}
	return -1;
}