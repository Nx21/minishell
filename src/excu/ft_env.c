/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 18:45:51 by nhanafi           #+#    #+#             */
/*   Updated: 2022/09/09 10:23:41 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_env(char **str, t_data *data)
{
    t_list *list;

    if(str[1])
    {
        ft_putstr_fd("env: ksd: No such file or directory", 2);
        return 127;
    }
    list = data->l_env;
    while(list)
    {
        if(list->value)
            printf("%s=%s\n", list->key, list->value);
        list = list->next;
    }
    return 0;
}