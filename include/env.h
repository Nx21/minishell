/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 01:14:17 by nhanafi           #+#    #+#             */
/*   Updated: 2022/08/28 02:29:26 by nhanafi          ###   ########.fr       */
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

typedef struct s_data
{
    t_list  *sorted_env;
    t_list  *env;
    t_list  last;
} t_data;

t_list	*add_one_sort(t_list *head, t_list *list);
t_list *env_list_sorted(t_list *head ,char **str);
t_list *env_list(char **str);
t_list *del_one(t_list *head, char *str);
#endif