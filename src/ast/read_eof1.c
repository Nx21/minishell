/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_eof.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 00:57:50 by nhanafi           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/09/15 22:48:06 by nhanafi          ###   ########.fr       */
=======
/*   Updated: 2022/09/15 16:15:31 by rjaanit          ###   ########.fr       */
>>>>>>> e69acf7582765843b05c4a37c5d8d2cf59a972db
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


static char *read_lines(char *eof, char *s)
{
	char	*str;
	char	*line;
	
	str = ft_strdup(s);
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
	str = ft_join(str, s);
	free(line);
	return (str);
}

t_node	*ft_read_eof(char *eof)
{
	t_var	*list;
	char	*line;
	char	*s;

	if(ft_instr(eof, '\"') >= 0 || ft_instr(eof, '\'') >= 0 )
		s = ft_strdup("\'");
	else
		s = ft_strdup("\"");
	eof = del_spc(eof);
	line = read_lines(eof, s);
	free(eof);
	if(!line)
		return NULL;
	list = malloc(sizeof(t_var));
	list->next = NULL;
	list->str = line;
	free(s);
	return (add_node(list, W));
}
