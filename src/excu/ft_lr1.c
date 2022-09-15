/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaanit <rjaanit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 23:21:19 by rjaanit           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/09/15 16:00:55 by nhanafi          ###   ########.fr       */
=======
/*   Updated: 2022/09/15 16:18:18 by rjaanit          ###   ########.fr       */
>>>>>>> e69acf7582765843b05c4a37c5d8d2cf59a972db
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	print_erro(char *str)
{
	ft_putstr_fd("minishell: ", 2);
	perror(str);
	return (1);
}

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
<<<<<<< HEAD
	{
		ft_putstr_fd("minishell: ", 2);
		perror(str[0]);
		return (1);
	}
=======
		return (print_erro(str[0]));
>>>>>>> e69acf7582765843b05c4a37c5d8d2cf59a972db
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
