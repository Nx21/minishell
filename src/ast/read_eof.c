/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_eof.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 00:57:50 by nhanafi           #+#    #+#             */
/*   Updated: 2022/08/28 00:58:10 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char *del_spc(char *buf)
{
	int len;
	
	while(*buf && ft_instr(" \n\t", *buf) >= 0)
		buf++;
	len = ft_strlen(buf) - 1;
	while(len >= 0 && ft_instr(" \n\t", buf[len]) >= 0)
		len--;
	buf[len + 1] = 0;
	return buf;
}

t_node	*ft_read_eof(char *eof)
{
	char	**buf;
	char	*line;

	eof = del_spc(eof);
	buf =  malloc(sizeof(char *) * 2);
	*buf = NULL;
	line =  readline("> ");
	while(line && ft_strcmp(line, eof))
	{
		*buf = ft_join(*buf, "\n");
		*buf = ft_join(*buf, line);
		line =  readline("> ");
	}
	buf[1] = NULL;
	return (add_node(buf, W));
}