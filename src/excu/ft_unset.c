/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 18:34:19 by nhanafi           #+#    #+#             */
/*   Updated: 2022/09/09 10:52:06 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_unset(char **str, t_data *data)
{
    int i;

    i = 1;
    while(str[i])
    {
        data->l_env = del_one(data->l_env, str[i]);
        i++;
    }
    return 0;
}