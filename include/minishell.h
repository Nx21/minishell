/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 01:23:45 by nhanafi           #+#    #+#             */
/*   Updated: 2022/09/08 13:42:04 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
#include <sys/types.h>
#include <sys/types.h>
#include <sys/wait.h>
# include "utils.h"
# include "ast.h"
# include "env.h"


typedef struct s_global
{
    int a;
    int b;
}   t_global;
char *ft_parcing(char *buf);
int G_global;
t_node *ft_ast_lev1(char *buf);
t_node *ft_ast_lev2(char *buf);
int		ft_echo(char **str);
int		ft_exit(char **str);
int ft_pwd(t_data *data);
t_node	*ft_read_eof(char *eof);
char    *ft_comp_oq(char *buf);
char    *ft_comp_op(char *buf);
t_node	*ft_read_eof(char *eof);
int     check_err_1(char *str);
int     check_err_2(char *str, int bool);

int	excu_ast(t_node *node, t_data *data);
int ft_or(t_node *node, t_data *data);
int ft_and(t_node *node, t_data *data);
int ft_pipe(t_node *node, t_data *data);
int     ft_drr(t_node *node, t_data *data);
int     ft_rr(t_node *node, t_data *data);
int     ft_dlr(t_node *node, t_data *data);
int     ft_lr(t_node *node, t_data *data);
int ft_word(t_node *node, t_data *data);
int	ft_cd(char **str, t_data *data);

#endif