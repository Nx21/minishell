/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaanit <rjaanit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 02:29:53 by nhanafi           #+#    #+#             */
/*   Updated: 2022/09/14 17:15:40 by rjaanit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

int	ft_putstr_fd(char *s, int fd)
{
	int		i;

	i = 0;
	while (s && s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	return (i);
}
