#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>

#define MAX_SIZE 1024

int main(int argc, char *argv[]){

	int fd[2];
	int status= pipe(fd);

	if(status< 0){
		perror("Error!\n");
		exit(1);
	}
	else{

		size_t pid;
		if((pid= fork())== 0){	
			close(fd[1]);
			dup2(fd[0], 0);
			close(fd[0]);
			int res= execlp("wc", "wc", NULL);
			_exit(1);

		}

		else{
			int bytes;
			char command[MAX_SIZE];
			close(fd[0]);
			while((bytes= read(0, command, MAX_SIZE))> 0)
				write(fd[1], command, bytes);
			close(fd[1]);
			wait(NULL);
		}
		return 0;
	}
}