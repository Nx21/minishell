/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 23:32:11 by nhanafi           #+#    #+#             */
/*   Updated: 2022/10/04 01:54:24 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_nflag(char *str)
{
	int	i;

	i = 1;
	if (str[0] != '-')
		return (0);
	while (str[i])
	{
		if (str[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

int	ft_echo(char **str)
{
	int	flag;

	str++;
	flag = 0;
	while (*str && check_nflag(*str))
	{
		str++;
		flag = 1;
	}
	while (*str)
	{
		printf("%s", *str);
		if(*str && *(str + 1))
			printf(" ");
		str++;
	}
	if (!flag)
		printf("\n");
	return (0);
}
