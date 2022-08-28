/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_err.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 00:17:26 by nhanafi           #+#    #+#             */
/*   Updated: 2022/08/28 01:17:20 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int check_err_1(char *str)
{
    static int i;
    int re = 0;

    i = 0;
    while (str[i] == ' ')
        i++;
    if (str[i] == '|' || str[i]=='&')
        return(0);
    while(str[i])
    {
        if ((str[i] == '|' && str[i+1] != '|') || (str[i] == '&' && str[i+1] != '&'))
            return(check_err_1(str + (i+1)));
        i++;
        if ( str[i] == '|' || str[i] == '&')
        {
            re++;
            if(re > 2)
                return(0);
        }
    }
    return(1);
}

int check_err_2(char *str, int bool)
{
    int i;
    int re = 0;
    i = 0;
    while (str[i] == ' ')
        i++;
    if (!str[i])
        return(0);
    if ((str[i] == '>' || str[i]=='<') && bool)
        return(0);
    if ((str[i] == '|' || str[i]=='&'))
        return(0);
    while(str[i])
    {
        if ((str[i] == '>' && str[i+1] != '>') || (str[i] == '<' && str[i+1] != '<'))
            return(check_err_2(str+i+1 ,1));
        i++;
        if ( str[i] == '>' || str[i] == '<')
        {
            re++;
            if(re > 2)
                return(0);
        }
    }
    return(1);
}