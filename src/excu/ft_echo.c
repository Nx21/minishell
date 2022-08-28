/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 23:32:11 by nhanafi           #+#    #+#             */
/*   Updated: 2022/08/27 23:52:28 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_echo(char **str)
{
	int	flag;

	flag = 1;
	if(ft_strcmp(*str, "-n"))
	{
		str++;
		flag = 1;
	}
	while(*str)
	{
		printf("%s ", *str);
		str++;
	}
	if(!flag)
		printf("\n");
	return (0);
}
