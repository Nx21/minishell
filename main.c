#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>

void handler(int sig)
{
	printf("SIGPIPE !\n");
	exit(sig);
}

int main()
{
	int fds[2];

	pipe(fds);

	int pid = fork();
	if (pid == 0)
	{
		dup2(fds[1],1);
		close(fds[0]);
		execvp("cat", (char *[]){"cat", NULL});
		exit(0);
	}

	pid = fork();
	if (pid == 0)
	{
		dup2(fds[0], 0);
		close(fds[1]);
		execvp("ls", (char *[]){"ls", NULL});
		exit(0);
	}

	close(fds[0]);
	close(fds[1]);

	int i = 0;
	while (i < 2)
	{
		int status;
		waitpid(-1, &status, 0);
		if (WIFEXITED(status))
			printf("The procces exited with -> %d\n", WEXITSTATUS(status));
		else if (WIFSIGNALED(status))	
			printf("The process exited with a signal -> %d - %s\n", WTERMSIG(status), strsignal(WTERMSIG(status)));
		i++;
	}
}

