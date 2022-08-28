#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>

int main()
{
	int	fd[2];
	int	stdout_fd = dup(STDOUT_FILENO);

	pipe(fd);
	dup2(fd[0], STDOUT_FILENO);
	printf("This test sould now go to the file out.txt\n");
	fflush(stdout);

	dup2(stdout_fd, STDOUT_FILENO);
	printf("This test sould now go to the STDOUT\n");
}