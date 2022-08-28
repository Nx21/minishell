/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 02:29:53 by nhanafi           #+#    #+#             */
/*   Updated: 2022/08/26 02:30:10 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

void ft_putstr_fd(char *s, int fd)
{
    int i;

    i = 0;
    while(s[i])
    {
        write(fd,&s[i],1);
        i++;
    }
}