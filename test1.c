// #include <stdio.h>
// #include <stdlib.h>
// #include <readline/readline.h>
// #include <readline/history.h>
// #include <string.h>
// #include <unistd.h>
// #include <fcntl.h>

// int ft_instr(char *str, char c)
// {
//     int i = 0;

//     while(str[i])
//     {
//         if(str[i] == c)
//             return 1;
//         i++;
//     }
//     return 0;
// }

// int ft_parcing(char *buf)
// {
//     int i;
//     char    c;

//     i = 0;
//     c = 0;
//     while(buf[i])
//     {
//         if(buf[i] == c)
//             c = 0;
//         else if(!c && ft_instr("\"\'", buf[i]))
//             c = buf[i];
//         else if(!c && ft_instr("(", buf[i]))
//             c = buf[i] + 1;
//         else if(!c && ft_instr(")}]", buf[i]))
//         {

//             return 1;
//         }
//         i++;
//     }
//     if(c)
//         ;
//     else
//         return 0;
// }


// int main() {
//     while (1) 
//     {
//         char *buf;

//         buf = readline("minishell-1.0$ ");
//         add_history(buf);
//         ft_parcing(buf);
//         free(buf);
//         if(ft_parcing(buf))
//             printf("error\n");
//         if(!*buf)
//             break;
//     }
// }


// #include<sys/wait.h>
// #include <stdlib.h>
// #include <stdio.h>
// #include <unistd.h>
// #define MSGSIZE 16
// char* msg1 = "hello, world #1";
// char* msg2 = "hello, world #2";
// char* msg3 = "hello, world #3";
  
// int main()
// {
//     char inbuf[MSGSIZE];
//     int p[2], i;
  
//     if (pipe(p) < 0)
//         exit(1);
  
//     /* continued */
//     /* write pipe */
  
//     write(p[1], msg1, MSGSIZE);
//     write(p[1], msg2, MSGSIZE);
//     write(p[1], msg3, MSGSIZE);
  
//     for (i = 0; i < 3; i++) {
//         /* read pipe */
//         read(p[0], inbuf, MSGSIZE);
//         printf("%d\n", p[1]);
//     }
    

//     return 0;
// }



// #include <stdio.h>
// #include <stdlib.h>	/* needed to define exit() */
// #include <unistd.h>	/* needed to define getpid() */
// #include <stdio.h>	
// // int main(int argc, char *argv[], char *envp[])
// // {
// //     while(*envp)
// //         printf("%s\n",*envp++);
// // }
// #include <stdlib.h>
// int main(int argc, char **argv, char **env)
// {
    
//     char *str[] = {"ls", "*.c", NULL};

//     // str = malloc(26);
//     // int i;
//     // for (i = 0; i <= 26; i++)
//     //     str[i] = 'a' +i;
//     // str[i] = 0;
//     // free(str);
//     // while(1);
//     execve("/bin/ls", str, env);
// }

// #include <dirent.h>
// #include <stdio.h>
 
// int main(void)
// {
//     DIR *d;
//     struct dirent *dir;
//     d = opendir("..");
//     d = opendir("push");
//     if (d)
//     {
//         while ((dir = readdir(d)) != NULL)
//         {
//             printf("%d   ",dir->d_type);
//             printf("%s\n", dir->d_name);
//         }
//         closedir(d);
//     }
//     return(0);
// }


#include <unistd.h>
#include <stdio.h>
// int main() {
//     char cwd[256];
//     int ch;

//     ch = chdir(path);
//     if(ch<0)
// 	{
//     	perror("cd: no such file or directory: ");
// 		return (1);
// 	}
//     printf("%d\n",chdir("src/ast"));
//     if (getcwd(cwd, sizeof(cwd)) == NULL)
//       perror("getcwd() error");
//     else
//       printf("current working directory is: %s\n", cwd);
   
//    return 0;
// }


#include <stdio.h>
#include <stdlib.h>

/* To shorten example, not using argp */
// int main (int argc, char *argv[], char *envp[])
// {
//   char *home, *host;

//   home = getenv("HOME");
//   host = getenv("_");

//   printf ("Your home directory is %s on %s.\n", home, host);

//   return 0;
// }

#include <stdio.h>
#include <stdlib.h>

/* To shorten example, not using argp */


#include "include/ast.h"

char	*ft_strdup(char *src)
{
	int		i;
	char	*c;

	i = 1;
	while (src[i-1] != 0)
		i++;
	c = (char *)malloc(i * sizeof(char));
	i = 0;
	while (src[i] != 0)
	{
		c[i] = src[i];
		i++;
	}
	c[i] = 0;
	return (c);
}
int    ft_strcmp(char *s1, char *s2)
{
    size_t            i;

    i = 0;
    while (s1[i] || s2[i])
    {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
        i++;
    }
    return (0);
}

char *ft_substr(char  *s, int start,int len)
{
    int i;
    char *str;

    str = (char *) malloc(sizeof(char)*(len+1));
    i = 0;
    while(i < len && s[i + start])
    {
        str[i] = s[i+start];
        i++;
    }
    str[i] = 0;
    return str;
}

// t_list *env_list(char **str)
// {
//     t_list *list;
//     int     i = 0;

//     while((*str)[i] != '=')
//         i++;
//     list = malloc(sizeof(t_list));
//     list->key = ft_substr(*str, 0, i);
//     list->value = ft_strdup(*str + i + 1);
//     list->next = NULL;
//     if(*(str + 1))
//         list->next = env_list(str + 1);
//     return list;
// }


// int check_error(char *str, int bool)
// {
//     int i;
//     int re = 0;
//     i = 0;
//     while (str[i] == ' ')
//         i++;
//     if (!str[i])
//         return(0);
//     if ((str[i] == '>' || str[i]=='<') && bool)
//         return(0);
//     if ((str[i] == '|' || str[i]=='&'))
//         return(0);
//     while(str[i])
//     {
//         if ((str[i] == '>' && str[i+1] != '>') || (str[i] == '<' && str[i+1] != '<'))
//             return(check_error(str+i+1 ,1));
//         i++;
//         if ( str[i] == '>' || str[i] == '<')
//         {
//             re++;
//             if(re > 2)
//                 return(0);
//         }
//     }
//     return(1);
// }

t_list	*add_one_sort(t_list *head, t_list *list)
{
	t_list *node;

	if(!head || ft_strcmp(head->key, list->key) > 0)
	{
		list->next = head;
		return list;
	}
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
			node->key = list->key;
			node->value = list->value;
			free(list);
			return head;
		}
		node = node->next;
	}
	node->next = list;
	return head;
}

t_list *env_list_sorted(t_list *head ,char **str)
{
    t_list *list;
    int     i = 0;

    while((*str)[i] != '=')
        i++;
    list = malloc(sizeof(t_list));
    list->key = ft_substr(*str, 0, i);
    list->value = ft_strdup(*str + i + 1);
    list->next = NULL;
	head = add_one_sort(head, list);
    if(*(str + 1))
        return env_list(head, str + 1);
    return head;
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
        list->next = env_list1(str + 1);
    return list;
}

int main(int argc, char **argv, char **envp)
{
    t_list *head;
    t_list *node;

    head = env_list(NULL, envp);
    node = head;
    while(node)
    {
        printf("declare -x %s=\"%s\"\n", node->key, node->value);
        node = node->next;
    }

    // printf("\n\n\n\n\n");
	// head = env_list1(envp);
    // node = head;
    // while(node)
    // {
    //     printf("%s=%s\n", node->key, node->value);
    //     node = node->next;
    // }
    // head = del_one(head, "_");
    // while(head)
    // {
    //     printf("%s\t%s\n", head->key, head->value);
    //     head = head->next;
    // }
}

// int	check_negative(char *str, int *i)
// {
// 	int	neg;

// 	neg = 0;
// 	while (str[*i] == ' ' || str[*i] == '\r' \
// 		|| str[*i] == '\n' || str[*i] == '\v' \
// 		|| str[*i] == '\f' || str[*i] == '\t')
// 		*i += 1;
// 	while (str[*i] == '-' || str[*i] == '+')
// 	{
// 		if (str[*i] == '-')
// 			neg++;
// 		*i += 1;
// 	}
// 	return (neg);
// }

// unsigned int	ft_atoi(char *str)
// {
// 	int	i;
// 	int	a;
// 	int	neg;

// 	i = 0;
// 	neg = check_negative(str, &i);
// 	a = 0;
// 	while (str[i] >= '0' && str[i] <= '9')
// 	{
// 		a *= 10;
// 		a += str[i] - 48;
//         a %= 256;
// 		i++;
// 	}
// 	if (neg % 2)
// 		a *= -1;
// 	return (a);
// }

// int main()
// {
//     printf("%d",ft_atoi("-2415613456515448") % 256);
// }

