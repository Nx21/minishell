#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdlib.h>

void handler(int sig)
{
    return ;
}

int main()
{

    signal(SIGTSTP, handler);
    int pid = fork();

    if (pid == 0)
    {
        signal(SIGTERM, SIG_DFL);
        execvp("cat", (char *[]){"cat", NULL});
        exit(0);
    }

    waitpid(pid, NULL, WUNTRACED);
    
    printf("finished!\n");
}
