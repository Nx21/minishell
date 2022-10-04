/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_ast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 03:40:46 by nhanafi           #+#    #+#             */
/*   Updated: 2022/10/03 04:20:06 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	excu_ast(t_node *node, t_data *data)
{
	if (node->token == OR)
		return (ft_or(node, data));
	if (node->token == AND)
		return (ft_and(node, data));
	if (node->token == DRR)
		return (ft_drr(node, data));
	if (node->token == PIPE)
		return (ft_pipe(node, data));
	if (node->token == RR)
		return (ft_rr(node, data));
	if (node->token == LR)
		return (ft_lr(node, data));
	if (node->token == DLR)
		return (ft_dlr(node, data));
	if (node->token == W)
		return (ft_word(node, data));
	if (node->token == PAR)
		return (ft_par(node, data));
	return (1);
}
