/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 00:14:29 by nhanafi           #+#    #+#             */
/*   Updated: 2022/08/25 00:45:04 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int    ft_strcmp(char *str1, char *str2)
{
    size_t            i;
    unsigned char    *s1;
    unsigned char    *s2;

    s1 = (unsigned char *)str1;
    s2 = (unsigned char *)str2;
    i = 0;
    while (s1[i] || s2[i])
    {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
        i++;
    }
    return (0);
}