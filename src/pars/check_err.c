/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_err.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 00:17:26 by nhanafi           #+#    #+#             */
/*   Updated: 2022/09/09 16:14:59 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_error(char *str)
{
    ft_putstr_fd("minishell: syntax error near unexpected token `", 2);
    write(2, str, 1 + (str[0] == str[1]));
    ft_putstr_fd("\'\n", 2);
    return 1;
}



int ft_check_par(char *str, int par)
{
    int res;

    if(par == -1)
        return ft_error(")");
    while(ft_instr(" \n\t", *str) >= 0)
        str++;
    res = ft_check_token(str, par);
    if(res >= 0)
        return res;
    if(*str)
    {
        ft_putstr_fd("minishell: syntax error near unexpected token `", 2);
        while(ft_isalnum(*str))
            write(2, str++, 1);
        ft_putstr_fd("\'\n", 2);
        return 1;
    }
    return 0;
}

int ft_check_token(char *str, int par)
{
    if(*str == '&' && str[1] == '&')
        return check_err(str + 2, AND, par);
    if(*str == '|' && str[1] == '|')
        return check_err(str + 2, OR, par);
    if(*str == '|')
        return check_err(str+ 1, PIPE, par);
    if(*str == '<' || *str == '>')
        return check_err(str + 1 + (*str == str[1]) , PIPE + 1, par);
    if(*str == '(')
        return ft_error(str);
    if(*str == ')')
        return ft_check_par(str+ 1, par - 1);
    return -1;
}

int check_err(char *str, t_token token, int par)
{
    int res;

    while(str && *str && ft_instr(" \n\t", *str) >= 0)
        str++;
    if(ft_instr("()><", *str) >= 0)
    {
        if(token > PIPE)
            return ft_error(str);
        else
        {
            par++;
            str++;
        }
    }
    if(ft_instr("|&", *str) >= 0)
        return ft_error(str);
    while(*str)
    {
        res = ft_check_token(str, par);
        if(res >= 0)
            return res;
        str++;
    }
    return 0;
}