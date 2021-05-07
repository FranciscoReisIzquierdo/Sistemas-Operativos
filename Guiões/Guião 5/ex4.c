#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>

#define MAX_SIZE 1024

int main(int argc, char *argv[]){

	size_t pid;
	int fd[2];
	int status= pipe(fd);

	if(status< 0){
		perror("Error!\n");
		exit(1);
	}
	if((pid= fork())== 0){
		close(fd[0]);
		dup2(fd[1], 1);
		execlp("ls", "ls", "/etc", NULL);
		close(fd[1]);
		_exit(1);
	}

	if((pid= fork())== 0){
		close(fd[1]);
		dup2(fd[0], 0);
		execlp("wc", "wc", "-l", NULL);
		close(fd[0]);
		_exit(1);
	}
	wait(NULL);
	return 0;
}