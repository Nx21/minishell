/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 23:34:57 by nhanafi           #+#    #+#             */
/*   Updated: 2022/09/24 02:51:57 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <limits.h>

int	ft_pwd(t_data *data)
{
	char	cwd[PATH_MAX];

	(void)data;
	getcwd(cwd, PATH_MAX);
	printf("%s\n", cwd);
	return (0);
}
