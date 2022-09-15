/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 23:21:19 by rjaanit           #+#    #+#             */
/*   Updated: 2022/09/15 14:57:26 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_lr(t_node *node, t_data *data)
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
	fd = open(str[0], O_RDONLY, 0777); 
	if (fd < 0)
	{
		ft_putstr_fd("minishell: ", 2);
		perror(node->right->list->str);
		return (1);
	}
	back_fd = dup(STDIN_FILENO);
	dup2(fd, STDIN_FILENO);
	close(fd);
	status = excu_ast(node->left, data);
	dup2(back_fd, STDIN_FILENO);
	free(s);
	free(str[0]);
	free(str);
	return (status);
}
