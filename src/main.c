/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 01:23:53 by nhanafi           #+#    #+#             */
/*   Updated: 2022/08/03 11:33:24 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_instr(char *str, char c)
{
    int i = 0;

    while(str[i])
    {
        if(str[i] == c)
            return 1;
        i++;
    }
    return 0;
}




int ft_parcing(char *buf)
{
    int i;
    char    c;

    i = 0;
    c = 0;
    while(buf[i])
    {
        if(buf[i] == c)
            c = 0;
        else if(!c && ft_instr("\"\'", buf[i]))
            c = buf[i];
        else if(!c && ft_instr("(", buf[i]))
            c = buf[i] + 1;
        else if(!c && ft_instr(")}]", buf[i]))
        {

            return 1;
        }
        i++;
    }
    if(c)
        return 1;
    else
        return 0;
}


int main() {
    while (1) 
    {
        char *buf;

        buf = readline("minishell-1.0$ ");
        add_history(buf);
        ft_parcing(buf);
        free(buf);
        if(ft_parcing(buf))
            printf("error\n");
        if(!*buf)
            break;
    }
}

