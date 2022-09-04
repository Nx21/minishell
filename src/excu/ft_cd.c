/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 23:34:01 by nhanafi           #+#    #+#             */
/*   Updated: 2022/09/04 10:37:57 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// int check_dir(char *path, t_data *data)
// {
// 	struct stat *buf
	
	
// 	if(!ft_strcmp(path, "."))
// 	{
// 		if(stat())
// 	}
	
// }


int	ft_cd(char *path)
{
	int ch;
	
	// if(s)
	ch = chdir(path);
    if (ch < 0)
	{
    	perror("minishell: ");
		return (1);
	}
	return (0);
}