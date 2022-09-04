/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_or_and.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 03:47:53 by nhanafi           #+#    #+#             */
/*   Updated: 2022/09/04 09:32:36 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_or(t_node *node, t_data *data)
{
    int state;

    state = excu_ast(node->left , data);
    if(state)
        state = excu_ast(node->right, data);
    return state;
}

int ft_and(t_node *node, t_data *data)
{
    int state;

    state = excu_ast(node->left , data);
    if(!state)
        state = excu_ast(node->right, data);
    return (state);
}