/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_expand.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 01:18:32 by nhanafi           #+#    #+#             */
/*   Updated: 2022/09/04 10:28:37 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"


char *var_alloc(char *var, char c)
{
	int len;
	int dq;
	int sq;

	len = 0;
	dq = 0;
	sq = 0;
	while(var[len])
	{
		if(var[len] == '\'')
			sq++;
		if(var[len] == '\"')
			dq++;
		len++;
	}
	if(c)
		return ft_calloc(sizeof(char), len + 4 * dq + 1);
	return ft_calloc(sizeof(char), len + 2 * dq + 2 * sq + 1);
}

char *find_var(char *str, t_data *data, char c)
{
	int	i;
	int	j;
	char *dst;
	char *var;

	var = find_one(data->l_env, str);
	dst = var_alloc(var, c);
	i = 0;
	j = 0;
	while(var[i])
	{
		if(c && var[i] == '\"'&& (j += 5))
			ft_strcat(dst, (char *)"\"\'\"\'\"");
		else if(!c && var[i] == '\"'&& (j += 3))
			ft_strcat(dst, (char *)"\'\"\'");
		else if(!c && var[i] == '\'' && (j += 3))
			ft_strcat(dst, (char *)"\"\'\"");
		else
			dst[j++] = var[i];
		i++;
	}
	free(str);
	free(var);
	return dst;
}

char	*var_handler_v(char *str, char c, t_data *data)
{
	int len;
	char *dst;
	char *tmp;

(void)c;
	len = 0;
	tmp = NULL;
	while(str[len] && (ft_isalnum(str[len]) || str[len] == '_'))
		len++;
	if(len)
		dst = find_var(ft_substr(str, 0, len), data, c);
	else
		dst = ft_strdup("$");
	if(str[len])
		tmp = var_handler(str + len, data, c);
	dst = ft_join(dst, tmp);
	free(tmp);
	return dst;
}

char	*var_handler(char *str, t_data *data, char c)
{
	int	len;
	char *tmp;
	char *dst;

	len = 0;
	dst = NULL;
	tmp = NULL;
	if(!str || !*str)
		return NULL;
	while(str[len])
	{
		if(c == str[len])
			c = 0;
		else if(!c && (str[len] == '\'' || str[len] == '\"'))
			c = str[len];
		else if (c != '\'' && str[len] == '$')
			break;
		len++;
	}
	dst = ft_substr(str, 0, len);
	if(str[len])
		tmp = var_handler_v(str + len + 1, c, data);
	dst = ft_join(dst, tmp);
	free(tmp);
	return dst;
}

t_var *list_expand_var(t_var *list, t_data *data)
{
	t_var	*lst;
	t_var	*next;
	char *str;
	
	if(!list)
		return NULL;
	next = list->next;
	str = var_handler(list->str, data, 0);	
	lst = list_split(str);
	free(str);
	free(list->str);
	free(list);
	list = lst;
	next = list_expand_var(next, data);
	list_append(list, next);
	return list;
}

t_var *list_expand_wc(t_var *list)
{
	t_var *next;
	t_var *node = NULL;

	if(!list)
		return NULL;
	next = list->next;
	list->next = NULL;
	if(ft_get_last_ind(list->str, "*") >= 0)
	{
		node = wc_handler(list->str, NULL);	
		if(node)
		{
			free(list->str);
			free(list);
			list = node;
		}
	}
	next = list_expand_wc(next);
	list_append(list, next);
	return list;
}

void list_expand_q(t_var *list)
{
	char *str;
	int	i;
	int	j;
	char c;

	if(!list)
		return ;
	c = 0;
	str =  malloc(ft_strlen(list->str) + 1);
	if(!str)
	{
		printf("here\n");
		exit(0);
	}
	i = 0;
	j = 0;
	while(list->str[j])
	{
		if(c == list->str[j])
			c = 0;
		else if(!c && (list->str[j] == '\'' || list->str[j] == '\"'))
			c = list->str[j];
		else
			str[i++] = list->str[j];
		j++;
	}
	str[i] = 0;
	free(list->str);
	list->str = str;
	list_expand_q(list->next);
}

t_var	*list_expand(t_var *list, t_data *data)
{
	// t_var *node;
	// t_var *next;
	// next = list
	(void)data;
	// if(!list)
	// 	return NULL;
	list = list_expand_var(list, data);
	list = list_expand_wc(list);
	list_expand_q(list);
	return list;
}


char **list_to_arr(t_var *list, t_data *data)
{
	char	**str;
	t_var	*node;
	int		i;
	
	list = list_expand(list, data);
	node = list;
	i = 0;
	while (node)
	{
		i++;
		node = node->next;
	}
	str = malloc(i * sizeof(char *) + 1);
	node = list;
	i = 0;
	while (node)
	{
		str[i] = node->str;
		list = node;
		node = node->next;
		free(list);
		i++;
	}
	str[i] = NULL;
	return str;
}