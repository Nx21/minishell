#include "minishell.h"

int     ft_dlr(t_node *node, t_data *data)
{
    int pid;

    // pid = fork();
    // (void) data;
    // (void) node;

    // if ( pid == 0 ) {
        int fd1[ 2 ];
        pipe( fd1 );
        int back_fd = dup(STDIN_FILENO);

        if ( (pid = fork()) > 0 ) {
            if (dup2( fd1[ 0 ] , STDIN_FILENO ) < 0) {
                perror("minishell:");
                return (1);
            }
            close( fd1[ 0 ] );
            close( fd1[ 1 ] ); // important; see below
            // Note: /usr/bin, not /bin
            excu_ast(node->left, data);
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
            if( node->right->str[0])
                printf("%s", node->right->str[0]);
            exit(0);
        }
        wait(0);
    //     exit(0);
    // }
    // wait(0);
    return 1;
}