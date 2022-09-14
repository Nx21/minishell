/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_comp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaanit <rjaanit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 00:16:57 by nhanafi           #+#    #+#             */
/*   Updated: 2022/09/14 18:04:11 by rjaanit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_comp_oq(char *buf)
{
	char	*line;

	line = readline("> ");
	if (!g_global)
		return (buf);
	if (!line)
	{
		ft_putstr_fd("minishell: unexpected EOF \
		while looking for matching `\"\'\n", 2);
		ft_putstr_fd("minishell: syntax error: unexpected end of file\n", 2);
		add_history(buf);
		free(buf);
		return (NULL);
	}
	buf = ft_join(buf, "\n");
	buf = ft_join(buf, line);
	free(line);
	return (ft_parcing(buf));
}

char	*ft_comp_op(char *buf)
{
	char	*line;

	line = readline("> ");
	if (!g_global)
		return (buf);
	if (!line)
	{
		ft_putstr_fd("minishell: syntax error: unexpected end of file\n", 2);
		add_history(buf);
		free(buf);
		return (NULL);
	}
	buf = ft_join(buf, " ");
	buf = ft_join(buf, line);
	free(line);
	return (ft_parcing(buf));
}
