/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 04:55:00 by rjaanit           #+#    #+#             */
/*   Updated: 2022/09/15 16:01:44 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	red_err(char *str, char **list)
{
	int i;
	ft_putstr_fd("minishell: ",2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": ambiguous redirect\n",2);
	i = 0;
	(void) list;
	free(str);
	while(list[i])
	{
		free(list[i]);
		i++;
	}
	free(list);
	return (1);
}

int	ft_drr(t_node *node, t_data *data)
{
	int		status;
	int		back_fd;
	int		fd;
	char	**str;
	char	*s;

	s = ft_strdup(node->right->list->str);
	str = list_to_arr(node->right->list, data);
	node->right->list = NULL;
	if (str[0] && str[1])
		return (red_err(s, str));
	fd = open(str[0], O_CREAT | O_RDWR | O_APPEND, 0777);
	status = 0;
	back_fd = dup(STDOUT_FILENO);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	status = excu_ast(node->left, data);
	dup2(back_fd, STDOUT_FILENO);
	free(s);
	free(str[0]);
	free(str);
	return (status);
}
