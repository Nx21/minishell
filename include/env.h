/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaanit <rjaanit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 01:14:17 by nhanafi           #+#    #+#             */
/*   Updated: 2022/09/16 02:33:34 by rjaanit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H
# include "utils.h"

typedef struct s_list
{
	char			*key;
	char			*value;
	int				tag;
	struct s_list	*next;
}t_list;

t_list	*add_one(t_list *head, t_list *list);
t_list	*append_one(t_list *head, char *key, char *value);
t_list	*env_list(char **str);
t_list	*del_one(t_list *head, char *str);
t_list	*new_list(char *key, char *val);
void	ft_printsort(t_list *head);
t_list	*append_one(t_list *head, char *key, char *value);
#endif