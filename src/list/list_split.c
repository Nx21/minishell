/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 23:41:21 by nhanafi           #+#    #+#             */
/*   Updated: 2022/09/16 00:50:53 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

t_var	*list_split(char *str)
{
	t_var	*list;
	int		i;
	char	c;

	while (str && *str && ft_instr("\n\t ", *str) >= 0)
		str++;
	if (!str || !*str)
		return (NULL);
	list = malloc(sizeof(t_var));
	i = 0;
	c = 0;
	while (str[i] && (c || ft_instr("\n\t ", str[i]) < 0))
	{
		if (str[i] == c)
			c = 0;
		else if (!c && ft_instr("\"\'", str[i]) >= 0)
			c = str[i];
		else if (!c && ft_instr("(", str[i]) >= 0)
			c = str[i] + 1;
		i++;
	}
	list->str = ft_substr(str, 0, i);
	list->next = list_split(str + i);
	return (list);
}
