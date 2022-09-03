/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wc_handler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 00:52:37 by nhanafi           #+#    #+#             */
/*   Updated: 2022/09/03 09:02:08 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

t_var *wc_all(char *str, char *path)
{
	t_var *head;
	DIR *dp;
    struct dirent *dirp;

	(void)str;
	head = NULL;
	if(path)
		dp = opendir(path);
	else
		dp = opendir(".");
	if(!dp)
		return NULL;
	while ((dirp = readdir(dp)) != NULL)
	{
		if(dirp->d_name[0] != '.' && wc_cmp(dirp->d_name, str))
			head = list_append(head, wc_creat(path, dirp->d_name));
	}
	free(path);
	closedir(dp);
	return head;
}

t_var *wc_dir(char *str, char *path)
{
	t_var *head;
	DIR *dp;
    struct dirent *dirp;

	head = NULL;
	if(path)
		dp = opendir(path);
	else
		dp = opendir(".");
	if(!dp)
		return (NULL);
	while ((dirp = readdir(dp)) != NULL)
	{
		if(dirp->d_type == 4 && dirp->d_name[0] != '.' && wc_cmp(dirp->d_name, str))
			head = list_append(head, wc_creat(path, dirp->d_name));
	}
	free(str);
	free(path);
	closedir(dp);
	return head;
}

t_var *wc_handler(char *str, char *path)
{
	int i;
	t_var *head;
	t_var *node;
	t_var *sub;

	i = 0;
	sub = NULL;
	head = NULL;
	if(str && *str == '/')
		return wc_handler(str + 1, ft_join(path, "/"));
	while(str && str[i] && str[i] != '/')
		i++;
	if(!str[i])
		return wc_all(str, path);
	head = wc_dir(ft_substr(str , 0 , i), path);
	if(!str[i + 1])
		return head;
	node = head;
	while(node)
	{
		sub = list_append(sub, wc_handler(str + i + 1, node->str));
        head = node;
		node = node->next;
        free(head);
	}
	return sub;
}