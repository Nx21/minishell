/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 01:23:53 by nhanafi           #+#    #+#             */
/*   Updated: 2022/08/16 20:33:53 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_node *ft_cmd(char *buf)
{
	return add_node(buf, W);
}

t_node *ft_pipe(char *buf)
{	
	int len;
	t_node	*node;
	
	if(!buf)
		return NULL;
	len = ft_get_last_ind(buf, "|");
	if(len == 0)
	{
		perror("syntax error near unexpected token `|\'");
		exit(1);
	}
	buf[len] = 0;
	if(len > 0)
	{
		node = add_node("pipe", PIPE);
		node->left = ft_pipe(buf);
		node->right = ft_cmd(buf + len + 1);
		printf("wahdbajbd : %s\n", buf + len + 1);
		return node;
	}
	return ft_cmd(buf);
}

void print_ast(t_node *node, int level)
{
	for (int i = 0; i < level; i++)
		printf("-----");
	printf("%s\n", node->str);
	if(node->left)
		print_ast(node->left, level + 1);
	if(node->right)
		print_ast(node->right, level + 1);
	
}


// void prin()
// {
// 	// int i = 0;
// 	while(LEV1)
// 	{
// 		printf("%d", LEV1);
		
// 	}
// }

int main() {
	char	*buf;
	pid_t		pid;
	t_node	*head;

	while (1) 
	{
		buf = readline("minishell-1.0$ ");
		if(!buf)
			break;
		buf = ft_parcing(buf);
		if(buf)
		{
			add_history(buf);
			pid = fork();
			if(pid == 0)
			{
			head = ft_pipe(buf);
			print_ast(head, 0);
				exit(0);
			}
			waitpid(pid, NULL, 0);
		}
		// printf("%d", ft_linstr(buf, "&&"));
		free(buf);
	}
}