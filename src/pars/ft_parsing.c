/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 06:27:59 by nhanafi           #+#    #+#             */
/*   Updated: 2022/08/28 01:18:19 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	buf_end(char *buf , int len)
{
	while(len >= 0 && ft_instr(" \n\t", buf[len]) >= 0)
		len--;
	if(buf[len] == '|' || buf[len] == '&' )
		return (1);
	return (0);
}

char *ft_parcing(char *buf)
{
	int		i;
	char	c;

	i = 0;
	c = 0;
	if(!(check_err_1(buf) && check_err_2(buf, 0)))
	{
		add_history(buf);
		free(buf);
		return NULL;
	}
	while(buf[i])
	{
		if(buf[i] == c)
			c = 0;
		else if(!c && ft_instr("\"\'", buf[i]) >= 0)
			c = buf[i];
		else if(!c && ft_instr("(", buf[i]) >= 0)
			c = buf[i] + 1;
		else if(!c && ft_instr(")]", buf[i]) >= 0)
			return buf;
		i++;
	}
	if (c)
		return ft_comp_oq(buf);
	if (buf_end(buf, i - 1))
		return ft_comp_op(buf);
	return buf;
}

