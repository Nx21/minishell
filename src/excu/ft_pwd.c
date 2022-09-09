/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 23:34:57 by nhanafi           #+#    #+#             */
/*   Updated: 2022/09/08 18:51:45 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_pwd(t_data *data)
{
	char cwd[2048];

	(void)data;
    printf("%s\n", getcwd(cwd, sizeof(cwd)));
	// printf("%s\n", find_one(data, "PWD"));
	// printf("%s\n", find_one(data, "OLDPWD"));
	return (0);
}