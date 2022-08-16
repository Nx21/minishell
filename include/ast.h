/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 13:17:27 by nhanafi           #+#    #+#             */
/*   Updated: 2022/08/16 03:04:18 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_H
# define AST_H

# include <stdlib.h>

typedef enum e_token
{
	W = 1,
	ARG = 1 << 1,
	LR = 1 << 2,
	RR = 1 << 3,
	DLR = 1 << 4,
	DRR = 1 << 5,
	PIPE = 1 << 7,
	SQ = 1 << 6,
}	t_token;

typedef struct s_node
{
	char			*str;
	t_token			token;
	struct s_node	*left;
	struct s_node	*right;
}   t_node;
t_node	*add_node(char *str, t_token token);

#endif