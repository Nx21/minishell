/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_or_and.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaanit <rjaanit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 03:47:53 by nhanafi           #+#    #+#             */
/*   Updated: 2022/08/29 19:33:01 by rjaanit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_or(t_node *node, t_data *data)
{
    int state;

    state = excu_ast(node->left , data);
    if(state)
        return excu_ast(node->right, data);
    return state;
}

int ft_and(t_node *node, t_data *data)
{
    int state;

    state = excu_ast(node->left , data);
    if(!state)
        return excu_ast(node->right, data);
    return (state);
}