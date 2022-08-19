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



#include <stdio.h>
#include <stdlib.h>	/* needed to define exit() */
#include <unistd.h>	/* needed to define getpid() */
#include <stdio.h>	
// int main(int argc, char *argv[], char *envp[])
// {
//     while(*envp)
//         printf("%s\n",*envp++);
// }
#include <stdlib.h>
int main(int argc, char **argv, char **env)
{
    
    char *str[] = {"ls", "*.c", NULL};

    // str = malloc(26);
    // int i;
    // for (i = 0; i <= 26; i++)
    //     str[i] = 'a' +i;
    // str[i] = 0;
    // free(str);
    // while(1);
    execve("/bin/ls", str, env);
}