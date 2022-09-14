/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaanit <rjaanit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 05:36:12 by nhanafi           #+#    #+#             */
/*   Updated: 2022/09/14 17:04:57 by rjaanit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	*ft_calloc(int number, int size)
{
	int		i;
	char	*c;

	i = 0;
	c = malloc(number * size);
	while (i < number * size)
	{
		c[i] = 0;
		i++;
	}
	return ((void *)c);
}
