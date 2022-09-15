/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaanit <rjaanit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 23:34:57 by nhanafi           #+#    #+#             */
/*   Updated: 2022/09/15 12:12:49 by rjaanit          ###   ########.fr       */
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
