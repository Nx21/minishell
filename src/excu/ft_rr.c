/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaanit <rjaanit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 21:40:11 by rjaanit           #+#    #+#             */
/*   Updated: 2022/09/15 15:25:47 by rjaanit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	print_err(void)
{
	perror("minishell");
	return (1);
}

int	ft_rr(t_node *node, t_data *data)
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
	fd = open(str[0], O_CREAT | O_RDWR | O_TRUNC, 0777);
	(void) data;
	if (fd < 0)
		return (print_err());
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
