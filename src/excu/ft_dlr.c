#include "minishell.h"

int     ft_dlr(t_node *node, t_data *data)
{
    int pid;
    int state = 0;

    pid = fork();
    if ( pid == 0 ) {
        int fd1[ 2 ];
        pipe( fd1 );
        int back_fd = dup(STDIN_FILENO);

        if ( (pid = fork()) > 0 ) {
            if (dup2( fd1[ 0 ] , STDIN_FILENO ) < 0) {
                perror("minishell:");
                return (1);
            }
            close( fd1[ 0 ] );
            close( fd1[ 1 ] );
            state = excu_ast(node->left, data);
            dup2(back_fd,STDIN_FILENO);
        }
        else if ( pid == 0 ) 
        {
            if (dup2( fd1[ 1 ] , 1 ) < 0) {
				perror("minishell:");
                return(1);
            }
            close( fd1[ 0 ] );
            close( fd1[ 1 ] );
            if( node->right->list)
                printf("%s", node->right->list->str);
            exit(0);
        }
        exit(state);
    }
    waitpid(pid, &state, 0);
    return 1;
}