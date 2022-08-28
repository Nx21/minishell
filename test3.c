#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>

int main()
{
	int fd = open("out.txt", O_CREAT | O_WRONLY, 0777);
	int	stdout_fd = dup(STDOUT_FILENO);

	dup2(fd, STDOUT_FILENO);
	write(1,"w45s",4);
	write(1,"w45s",4);
	write(1,"w45s",4);

	dup2(stdout_fd, STDOUT_FILENO);
	printf("This test sould now go to the STDOUT\n");
}