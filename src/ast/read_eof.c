/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_eof.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 00:57:50 by nhanafi           #+#    #+#             */
/*   Updated: 2022/09/01 00:35:09 by nhanafi          ###   ########.fr       */
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
	t_var	*list;
	char	*line;

	eof = del_spc(eof);
	list =  malloc(sizeof(t_var));
	list->next = NULL;
	list->str = NULL;
	line =  readline("> ");
	while(line && ft_strcmp(line, eof))
	{
		list->str = ft_join(list->str , "\n");
		list->str = ft_join(list->str , line);
		line =  readline("> ");
	}
	return (add_node(list, W));
}