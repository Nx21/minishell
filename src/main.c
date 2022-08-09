/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 01:23:53 by nhanafi           #+#    #+#             */
/*   Updated: 2022/08/04 10:14:11 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main() {
	char	*buf;

	while (1) 
	{
		buf = readline("minishell-1.0$ ");
		if(!buf)
			break;
		buf = ft_parcing(buf);
		add_history(buf);
		free(buf);
	}
}

