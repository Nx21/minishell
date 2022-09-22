/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 13:17:27 by nhanafi           #+#    #+#             */
/*   Updated: 2022/09/21 17:19:32 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_H
# define AST_H

# include <stdio.h>
# include <stdlib.h>
# include <dirent.h>
# include "utils.h"
# include "env.h"

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
	PAR = 11,
	N = 12
}	t_token;

typedef struct s_data
{
	struct s_list	*l_env;
	char			**env;
	struct s_list	*last;
	char			*state;
}t_data;

typedef struct s_var
{
	struct s_var	*next;
	char			*str;
}t_var;

typedef struct s_node
{
	t_var			*list;
	t_token			token;
	struct s_node	*left;
	struct s_node	*right;
}t_node;

t_node	*add_node(t_var *list, t_token token);
t_var	*list_split(char *str);
char	*list_join(t_var *list);
t_node	*ft_cmd(char *buf);
t_node	*ft_ast_lev1(char *buf);
t_node	*ft_ast_lev2(char *buf);
t_node	*ft_ast_lev3(char *buf);
t_node	*ft_read_eof(char *eof);
t_var	*list_append(t_var *head, t_var *var);
int		wc_cmp(char *s1, char *s2);
t_var	*wc_creat(char *path, char *name);
t_var	*wc_handler(char *str, char *path);
char	**list_to_arr(t_var *list, t_data *data);
char	*var_handler(char *str, t_data *data, char c);
char	*var_handler_v(char *str, char c, t_data *data);
t_var	*list_expand_var(t_var *list, t_data *data);
char	*ft_itoa(int n);
char	*find_one(t_data *data, char *key);
int		red_err(char *str, char **list);
char	*del_qu(char *buf);
void	list_expand_q(t_var *list);
t_var	*list_expand_var(t_var *list, t_data *data);
char	*find_var(char *str, t_data *data, char c);
#endif