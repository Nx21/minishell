/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaanit <rjaanit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 23:34:43 by nhanafi           #+#    #+#             */
/*   Updated: 2022/09/14 15:20:41 by rjaanit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_isdigit(int str)
{
	if (str >= '0' && str <= '9')
		return (1);
	else
		return (0);
}

int	is_numeric(char *str)
{
	while (*str)
	{
		if (ft_isdigit(*str) == 0 || *str == '-')
			return (0);
		str++;
	}
	return (1);
}

int	how_many_arg(char **str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_exit(char **str)
{
	printf("exit\n");
	if (str[1] && !is_numeric(str[1]))
	{
		printf("%s: numeric argument required\n", str[1]);
		exit(1);
	}
	if (how_many_arg(str) > 2)
	{
		printf("too many arguments \n");
		return (1);
	}
	exit (ft_atoi(str[1]));
}
