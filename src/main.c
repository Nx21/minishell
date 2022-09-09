/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 01:23:53 by nhanafi           #+#    #+#             */
/*   Updated: 2022/09/09 14:25:26 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"



void free_ast(t_node *node)
{
	t_var *list;
	list =  node->list;
	while (list)
	{
		list = node->list->next;
		free(node->list->str);
		free(node->list);
		node->list = list;
	}

	if(node->left)
		free_ast(node->left);
	if(node->right)
		free_ast(node->right);
	free(node);
}

t_data *get_data(char **envp)
{
	t_data *data;

	data = malloc(sizeof(t_data));
	data->env = envp;
	data->state = NULL;
	// data->sort_env = env_list_sorted(NULL,envp);
	data->l_env = env_list(envp);
	data->last =  NULL;
	return data;
}


void    handler(int num)
{
	if (num == SIGQUIT)
		return ;
	if(!G_global)
	{
        printf("\n");
		rl_replace_line("", 0);
        rl_on_new_line();
        rl_redisplay();
	}
	else 
	{
		G_global = 0;
		int fd[2];
		pipe(fd);
   		dup2(fd[0], STDIN_FILENO);
		ft_putstr_fd("\n", fd[1]);
	}

}


int main(int argc, char **argv, char **envp) 
{
	char	*buf;
	t_node	*head;
	int back_fd = dup(STDIN_FILENO);
	t_data	*data;
	char	*st;

	(void)argc;
	(void)argv;
	rl_catch_signals = 0;
	signal(SIGINT, handler);
	// signal(SIGQUIT, handler);
	data = get_data(envp);
	while (1)
	{
		dup2(back_fd, STDIN_FILENO);
		G_global = 0;
        rl_on_new_line();
		buf = readline("minishell-1.0$ ");
		if(!buf)
			break;
		G_global = 1;
		buf = ft_parcing(buf);
		if(buf && G_global)
		{
			add_history(buf);
			head = ft_ast_lev1(buf);
			st = ft_itoa(excu_ast(head, data) % 256);
			free(data->state);
			data->state = st;
			free_ast(head);
		}
		if(buf)
			free(buf);
	}
	rl_clear_history();
	// handler(0);

}
