/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaanit <rjaanit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 18:34:19 by nhanafi           #+#    #+#             */
/*   Updated: 2022/09/14 15:45:03 by rjaanit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_unset(char **str, t_data *data)
{
	int		i;

	i = 1;
	while (str[i])
	{
		data->l_env = del_one(data->l_env, str[i]);
		i++;
	}
	return (0);
}
