/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 01:23:53 by nhanafi           #+#    #+#             */
/*   Updated: 2022/09/03 09:57:55 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"



void print_ast(t_node *node, int level, t_data *data)
{
	// t_var *list;
	char **str;
	int i =0;

	for (int i = 0; i < level; i++)
		printf("-----");
	str = list_to_arr(node->list, data);
	while(str[i])
	{
		printf("|%s|  ", str[i]);
		free(str[i]);
		i++;
	}
	free(str);
	printf("  %d\n", node->token);
	if(node->left)
		print_ast(node->left, level + 1, data);
	if(node->right)
		print_ast(node->right, level + 1, data);
	free(node);
}

void    ft_signal_ctrl_c(int sig)
{
    (void)sig;
    write(2, "\n", 1);
    rl_replace_line("", 0);
    rl_on_new_line();
    rl_redisplay();
}

t_data *get_data(char **envp)
{
	t_data *data;

	data = malloc(sizeof(t_data));
	data->env = envp;
	data->sort_env = env_list_sorted(NULL,envp);
	data->unsort_env = env_list(envp);
	data->last =  NULL;
	return data;
}

int main(int argc, char **argv, char **envp) 
{
	char	*buf;
	t_node	*head;
	// t_list	*env;
	t_data	*data;

	(void)argc;
	(void)argv;
	// env = env_list(envp);
	// rl_catch_signals = 0;
	// signal(SIGINT, ft_signal_ctrl_c);
	data = get_data(envp);
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
			// print_ast(head, 0, data);
			excu_ast(head, data);
			free(buf);
		}
	}
	rl_replace_line("exit", 0);
    rl_on_new_line();
    rl_redisplay();
}
