/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 01:23:53 by nhanafi           #+#    #+#             */
/*   Updated: 2022/08/27 01:02:43 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char *del_spc(char *buf)
{
	int len;
	
	while(*buf && ft_instr(" \n\t", *buf) >= 0)
		buf++;
	len = ft_strlen(buf) - 1;
	while(len >= 0 && ft_instr(" \n\t", buf[len]) >= 0)
		len--;
	buf[len + 1] = 0;
	return buf;
}

t_node *ft_cmd(char *buf)
{
	int	len;

	while(*buf && ft_instr(" \n\t", *buf) >= 0)
		buf++;
	len = ft_strlen(buf) - 1;
	while(len >= 0 && ft_instr(" \n\t", buf[len]) >= 0)
		len--;
	if(buf[0] == '(' && buf[len] == ')')
	{
		buf[len] = 0;
		buf++;
		return ft_ast_lev1(buf);
	}
	buf[len + 1] = 0;
	return add_node(ft_split(buf, ' '), W);
}

t_node *ft_ast_lev1(char *buf)
{	
	int len;
	t_node	*node;
	t_token token;
	
	if(!buf)
		return NULL;
	len = find_lev1(&token, buf);
	if(len > 0)
	{
		buf[len - 1] = 0;
		node = add_node(NULL, token);
		node->left = ft_ast_lev1(buf);
		node->right = ft_ast_lev2(buf + len + 1);
		return node;
	}
	return ft_ast_lev2(buf);
}

t_node	*ft_read_eof(char *eof)
{
	char	**buf;
	char	*line;

	eof = del_spc(eof);
	buf =  malloc(sizeof(char *) * 2);
	*buf = NULL;
	line =  readline("> ");
	while(line && ft_strcmp(line, eof))
	{
		*buf = ft_join(*buf, "\n");
		*buf = ft_join(*buf, line);
		line =  readline("> ");
	}
	buf[1] = NULL;
	return (add_node(buf, W));
}


t_node *ft_ast_lev2(char *buf)
{	
	int len;
	t_node	*node;
	t_token token;
	
	if(!buf)
		return NULL;
	len = find_lev2(&token, buf);
	if(len > 0)
	{
		buf[len - (token < 4)] = 0;
		node = add_node(NULL, token);
		node->left = ft_ast_lev2(buf);
		if (token == DLR)
			node->right = ft_read_eof(buf + len + 1);
		else
			node->right = ft_cmd(buf + len + 1);
		return node;
	}
	return ft_cmd(buf);
}

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

int ft_echo(char **str)
{
	int	flag;

	flag = 1;
	if(ft_strcmp(*str, "-n"))
	{
		str++;
		flag = 1;
	}
	while(*str)
	{
		printf("%s ", *str);
		str++;
	}
	if(!flag)
		printf("\n");
	return (0);
}

int	ft_cd(char *path)
{
	int ch;
	
	ch = chdir(path);
    if (ch < 0)
	{
    	perror("minishell: ");
		return (1);
	}
	return (0);
}

int ft_pwd(void)
{
	char cwd[1024];

    printf("%s\n", getcwd(cwd, sizeof(cwd)));
	return (0);
}

t_list *env_list(char **str)
{
    t_list *list;
    int     i = 0;

    while((*str)[i] != '=')
        i++;
    list = malloc(sizeof(t_list));
    list->key = ft_substr(*str, 0, i);
    list->value = ft_strdup(*str + i + 1);
    list->next = NULL;
    if(*(str + 1))
        list->next = env_list(str + 1);
    return list;
}
void del_list(t_list *node)
{
	free(node->key);
	free(node->value);
	free(node);
}

t_list *del_one(t_list *head, char *str)
{
	t_list	*node;
	t_list	*next;

	node = head;
	if(node && !ft_strcmp(str, node->key))
	{
		head = node->next;
		del_list(node);
		return head;
	}
	while(node && node->next)
	{
		if(!ft_strcmp(str, node->next->key))
		{
			next = node->next;
			node->next = next->next;
			del_list(next);
			break;
		}
		node = node->next;
	}
	return head;	
}

t_list *add_one(t_list *head, char *key, char *val, int flag)
{
	t_list *list;
	t_list *node;

	list = malloc(sizeof(t_list));
	list->key = key;
	list->value = val;
	list->next= NULL;
	if(!head)
		return list;
	node = head;
	while(node->next)
	{
		if(!ft_strcmp(node->key, list->key))
		{
			node->key = key;
			node->value = val;
			free(list);
			return head;
		}
		node = node->next;
	}
	node->next = list;
	return head;
}

t_list	add_one_sort(t_list *head, char *key, char *val, int flag)
{
	t_list *list;
	t_list *node;

	list = malloc(sizeof(t_list));
	list->key = key;
	list->value = val;
	list->next= NULL;
	if(!head || ft_strcmp(node->key, list->key) > 0)
		return list;
	node = head;
	while(node->next)
	{
		if(ft_strcmp(node->next->key, list->key) > 0)
		{
			list->next = node->next;
			node->next = list;
			return head;
		}
		if(!ft_strcmp(node->key, list->key))
		{
			node->key = key;
			node->value = val;
			free(list);
			return head;
		}
		node = node->next;
	}
	node->next = list;
	return head;
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