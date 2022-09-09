/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 06:27:59 by nhanafi           #+#    #+#             */
/*   Updated: 2022/09/09 20:16:00 by nhanafi          ###   ########.fr       */
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

int	check_op(char *buf)
{
	int		i;
	char	c;
	int		par;

	i = 0;
	c = 0;
	par = 0;
	while(buf[i])
	{
		if(buf[i] == c)
			c = 0;
		else if(!c && ft_instr("\"\'", buf[i]) >= 0)
			c = buf[i];
		else if(!c && buf[i] == '(')
			par++;
		else if(!c && buf[i] == ')')
			par--;
		i++;
	}
	return c || par;
}

char *ft_parcing(char *buf)
{
	int	c;

	if((check_err(buf , 0, 0)))
	{
		add_history(buf);
		free(buf);
		return NULL;
	}
	c = check_op(buf);
	if (c)
		return ft_comp_oq(buf);
	if (buf_end(buf, ft_strlen(buf) - 1))
		return ft_comp_op(buf);
	return buf;
}

