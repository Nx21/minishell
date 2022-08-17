/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 09:17:28 by nhanafi           #+#    #+#             */
/*   Updated: 2022/08/17 02:22:00 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
#include "ast.h"
# include <stdlib.h>

int		ft_strlen(char *str);
char	*ft_join(char *s1, char *s2);
int     ft_instr(char *str, char c);
char    ft_substr(char *s, unsigned int start, size_t len);
int     ft_get_last_ind(char *str, char *to_find);
// int	    ft_instr(char *str, char to_find);
int	find_lev1(t_token *token, char *str);
int	find_lev2(t_token *token, char *str);
#endif