/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wc_creat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 01:08:06 by nhanafi           #+#    #+#             */
/*   Updated: 2022/09/16 00:57:34 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

t_var	*wc_creat(char *path, char *name)
{
	t_var	*var;

	var = malloc(sizeof(t_var));
	var->str = NULL;
	var->str = ft_strdup(path);
	if (path && path[0] != '/')
		var->str = ft_join(var->str, "/");
	var->str = ft_join(var->str, name);
	var->next = NULL;
	return (var);
}
