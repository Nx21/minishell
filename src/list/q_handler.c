/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   q_handler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 20:29:29 by nhanafi           #+#    #+#             */
/*   Updated: 2022/09/15 23:57:29 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

char	*del_qu(char *buf)
{
	char	*str;
	int		i;
	int		j;
	char	c;

	str = malloc(ft_strlen(buf) + 1);
	if (!str)
		exit(1);
	i = 0;
	j = 0;
	c = 0;
	while (buf[j])
	{
		if (c == buf[j])
			c = 0;
		else if (!c && (buf[j] == '\'' || buf[j] == '\"'))
			c = buf[j];
		else
			str[i++] = buf[j];
		j++;
	}
	str[i] = 0;
	return (str);
}

void	list_expand_q(t_var *list)
{
	char	*str;

	if (!list)
		return ;
	str = del_qu(list->str);
	free(list->str);
	list->str = str;
	list_expand_q(list->next);
}
