/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 23:37:26 by nhanafi           #+#    #+#             */
/*   Updated: 2022/08/27 23:54:06 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

t_node *ft_cmd(char *buf)
{
	int	len;

	while(*buf && ft_instr(" \n\t", *buf) >= 0)
		buf++;
	len = ft_strlen(buf) - 1;
	while(len >= 0 && ft_instr(" \n\t", buf[len]) >= 0)
		len--;
	if(buf[0] == '(' && buf[len] == ')')
	{
		buf[len] = 0;
		buf++;
		return ft_ast_lev1(buf);
	}
	buf[len + 1] = 0;
	return add_node(ft_split(buf, ' '), W);
}