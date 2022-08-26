/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parcing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 06:27:59 by nhanafi           #+#    #+#             */
/*   Updated: 2022/08/26 03:39:17 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int check_error(char *str)
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
            return(check_error(str + (i+1)));
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

char *ft_comp_oq(char *buf)
{
	char	*line;

	line = readline("> ");
	if(!line)
	{
		ft_putstr_fd("minishell: unexpected EOF while looking for matching `\"\'\n", 2);
		ft_putstr_fd("minishell: syntax error: unexpected end of file", 2);
		add_history(buf);
		free(buf);
		return NULL;
	}
	buf = ft_join(buf, "\n");
	buf = ft_join(buf, line);
	free(line);
	return ft_parcing(buf);
}

char *ft_comp_op(char *buf)
{
	char	*line;

	line = readline("> ");
	if(!line)
	{
		ft_putstr_fd("minishell: syntax error: unexpected end of file\n",2);
		add_history(buf);
		free(buf);
		return NULL;
	}
	buf = ft_join(buf, line);
	free(line);
	return ft_parcing(buf);
}

int	buf_end(char *buf , int len)
{
	while(len >= 0 && ft_instr(" \n\t", buf[len]) >= 0)
		len--;
	if(buf[len] == '|' || buf[len] == '&' )
		return (1);
	return (0);
}



char *ft_parcing(char *buf)
{
	int		i;
	char	c;

	i = 0;
	c = 0;
	if(!check_error(buf))
	{
		free(buf);
		add_history(buf);
		return NULL;
	}
	while(buf[i])
	{
		if(buf[i] == c)
			c = 0;
		else if(!c && ft_instr("\"\'", buf[i]) >= 0)
			c = buf[i];
		else if(!c && ft_instr("(", buf[i]) >= 0)
			c = buf[i] + 1;
		else if(!c && ft_instr(")]", buf[i]) >= 0)
			return buf;
		i++;
	}
	if (c)
		return ft_comp_oq(buf);
	if (buf_end(buf, i - 1))
		return ft_comp_op(buf);
	return buf;
}
