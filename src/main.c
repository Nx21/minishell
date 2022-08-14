/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 01:23:53 by nhanafi           #+#    #+#             */
/*   Updated: 2022/08/14 02:55:35 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_node *ft_pipe(char *buf)
{	
	int len;
	t_node	*head;
	
	if(!buf)
		return NULL;
	head  = NULL;
	len = ft_linstr(buf, "&&");
	printf("%d \n", len);
	buf[len] = 0;
	printf("%s\n", buf);
	printf("%s\n", buf + len + 2);
	return head;
}



int main() {
	char	*buf;

	while (1) 
	{
		buf = readline("minishell-1.0$ ");
		if(!buf)
			break;
		buf = ft_parcing(buf);
		if(buf)
		{
			add_history(buf);
			ft_pipe(buf);
		}
		// printf("%d", ft_linstr(buf, "&&"));
		
		free(buf);
	}
}

