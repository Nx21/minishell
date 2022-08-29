/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaanit <rjaanit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 13:17:27 by nhanafi           #+#    #+#             */
/*   Updated: 2022/08/29 23:14:07 by rjaanit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_H
# define AST_H

# include <stdlib.h>
# include "utils.h"
typedef enum e_token
{
	OR = 1,
	AND = 2,
	PIPE = 3,
	DLR = 4,
	DRR = 5,
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

t_node	*ft_cmd(char *buf);
t_node	*add_node(char **str, t_token token);
t_node *ft_ast_lev1(char *buf);
t_node *ft_ast_lev2(char *buf);
t_node *ft_ast_lev3(char *buf);
t_node	*ft_read_eof(char *eof);

#endif