/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 09:17:28 by nhanafi           #+#    #+#             */
/*   Updated: 2022/08/18 02:16:21 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
#include "ast.h"
# include <stdlib.h>

int		ft_strlen(char *str);
char	*ft_join(char *s1, char *s2);
int     ft_instr(char *str, char c);
int     ft_get_last_ind(char *str, char *to_find);
// int	    ft_instr(char *str, char to_find);
int	find_lev1(t_token *token, char *str);
int	find_lev2(t_token *token, char *str);
char	*ft_strdup(char *src);
char	*ft_substr(char *s, int start, int len);
char	**ft_split(char *s, char c);
#endif