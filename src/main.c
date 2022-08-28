/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 01:23:53 by nhanafi           #+#    #+#             */
/*   Updated: 2022/08/28 01:13:12 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"



void print_ast(t_node *node, int level)
{
	int i = 0;
	for (int i = 0; i < level; i++)
		printf("-----");
	while(node->str && node->str[i])
		printf("|%s|  ", node->str[i++]);
	printf("  %d\n", node->token);
	if(node->left)
		print_ast(node->left, level + 1);
	if(node->right)
		print_ast(node->right, level + 1);
	
}


int main(int argc, char **argv, char **envp) 
{
	char	*buf;
	t_node	*head;
	t_list	*env;

	(void)argc;
	(void)argv;
	env = env_list(envp);
	while (1)
	{
		buf = readline("minishell-1.0$ ");
		if(!buf)
			break;
		buf = ft_parcing(buf);
		if(buf)
		{
			add_history(buf);
			head = ft_ast_lev1(buf);
			print_ast(head, 0);
			free(buf);
		}
	}
}
