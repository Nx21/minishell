/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 01:23:53 by nhanafi           #+#    #+#             */
/*   Updated: 2022/09/04 10:28:28 by nhanafi          ###   ########.fr       */
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
    printf("nasr");
    // rl_replace_line("", 0);
    // rl_on_new_line();
    // rl_redisplay();
}

t_data *get_data(char **envp)
{
	t_data *data;

	data = malloc(sizeof(t_data));
	data->env = envp;
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
        rl_redisplay();
	}

}


int main(int argc, char **argv, char **envp) 
{
	char	*buf;
	t_node	*head;
	int back_fd = dup(STDIN_FILENO);
	t_data	*data;

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
			// print_ast(head, 0, data);
			excu_ast(head, data);
		}
		if(buf)
			free(buf);
	}
	rl_clear_history();
	// handler(0);

}
