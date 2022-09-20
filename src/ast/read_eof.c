/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_eof.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 23:54:28 by nhanafi           #+#    #+#             */
/*   Updated: 2022/09/19 21:48:30 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*del_spc(char *buf)
{
	int		len;
	char	*str;

	while (*buf && ft_instr(" \n\t", *buf) >= 0)
		buf++;
	len = ft_strlen(buf) - 1;
	while (len >= 0 && ft_instr(" \n\t", buf[len]) >= 0)
		len--;
	buf[len + 1] = 0;
	str = del_qu(buf);
	return (str);
}

static char	*read_lines(char *eof)
{
	char	*str;
	char	*line;

	str = NULL;
	line = readline("> ");
	while (line && ft_strcmp(line, eof))
	{
		str = ft_join(str, line);
		free(line);
		if (!g_global)
		{
			free(str);
			return (NULL);
		}
		str = ft_join(str, "\n");
		line = readline("> ");
	}
	free(line);
	return (str);
}

t_node	*ft_read_eof(char *eof)
{
	t_var	*list;
	char	*line;
	int		token;

	if (ft_instr(eof, '\"') >= 0 || ft_instr(eof, '\'') >= 0)
		token = N;
	else
		token = W;
	eof = del_spc(eof);
	line = read_lines(eof);
	free(eof);
	if (!line)
		return (NULL);
	list = malloc(sizeof(t_var));
	list->next = NULL;
	list->str = line;
	return (add_node(list, token));
}
