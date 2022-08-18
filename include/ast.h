/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 13:17:27 by nhanafi           #+#    #+#             */
/*   Updated: 2022/08/18 02:13:01 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_H
# define AST_H

# include <stdlib.h>

typedef enum e_token
{
	OR = 1,
	AND = 2,
	DLR = 3,
	DRR = 4,
	PIPE = 5,
	LR = 6,
	RR = 7,
	W = 8,
	ARG = 9,
	SQ = 10,
}	t_token;

typedef struct s_node
{
	char			**str;
	t_token			token;
	struct s_node	*left;
	struct s_node	*right;
}   t_node;
t_node	*add_node(char **str, t_token token);

#endif