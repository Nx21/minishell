/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 01:14:17 by nhanafi           #+#    #+#             */
/*   Updated: 2022/09/08 12:08:40 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H
#include "utils.h"
typedef struct s_list
{
	char			*key;
	char			*value;
	int				tag;
	struct s_list	*next;
}   t_list;


t_list	*add_one(t_list *head, t_list *list);
t_list *env_list_sorted(t_list *head ,char **str);
t_list *env_list(char **str);
t_list *del_one(t_list *head, char *str);
char	*find_one(t_list *head, char *str);
t_list *new_list(char *key, char *val);
#endif