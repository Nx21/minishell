/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parcing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 06:27:59 by nhanafi           #+#    #+#             */
/*   Updated: 2022/08/14 02:48:39 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char *ft_comp_line(char *buf)
{
	char	*line;

	line = readline("> ");
	if(!line)
	{
		perror("minishell: unexpected EOF while looking for matching `\"\'\nminidhell: syntax error: unexpected end of file");
		free(buf);
		return NULL;
	}
	buf = ft_join(buf, "\n");
	buf = ft_join(buf, line);
	free(line);
	return ft_parcing(buf);
}

char *ft_parcing(char *buf)
{
	int		i;
	char	c;

	i = 0;
	c = 0;
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
	if(c)
		return ft_comp_line(buf);
	else
	{
		// if(buf)
		// 	printf("%s\n", buf);
		return buf;
	}
}
