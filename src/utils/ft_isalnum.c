/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 04:48:53 by nhanafi           #+#    #+#             */
/*   Updated: 2022/09/03 04:49:08 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"utils.h"

int    ft_isalnum( int str )
{
    if ((str >= 48 && str <= 57)
        || (str >= 65 && str <= 90)
        || (str >= 97 && str <= 122))
    {
        return (1);
    }
    else
        return (0);
}