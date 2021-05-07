#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>

#define MAX_SIZE 1024

int main(int argc, char *argv[]){

	// 1-> Output; 0-> Input
	// Temos n comandos, logo matriz será de n-1 linhas (n= 4 neste caso)
	int pipes[2][2];

	if(pipe(pipes[0])< 0){
		perror("Error!\n");
		exit(1);
	}
	else{
		if(fork()== 0){
			close(pipes[0][0]);
			dup2(pipes[0][1], 1);
			close(pipes[0][1]);
			execlp("grep", "grep", "-v", "ˆ#", "/etc/passwd", NULL);
			_exit(1);
		}
		close(pipes[0][1]);
	}

	if(pipe(pipes[1])< 0){
		perror("Error!\n");
		exit(1);
	}
	else{
		if(fork()== 0){
			close(pipes[1][0]);
			dup2(pipes[0][0], 0);
			close(pipes[0][0]);
			dup2(pipes[1][1], 1);
			close(pipes[1][1]);

			execlp("cut", "cut", "-f7", "-d:", NULL);
			_exit(1);
		}
		close(pipes[0][0]);
		close(pipes[1][1]);
	}

	if(pipe(pipes[2])< 0){
		perror("Error!\n");
		exit(1);
	}
	else{
		if(fork()== 0){
			close(pipes[2][0]);
			dup2(pipes[1][0], 0);
			close(pipes[1][0]);
			dup2(pipes[2][1], 1);
			close(pipes[2][1]);

			execlp("uniq", "uniq", NULL, NULL);
			_exit(1);
		}
		close(pipes[1][0]);
		close(pipes[2][1]);
	}


	if(fork()== 0){
		dup2(pipes[2][0], 0);
		close(pipes[2][0]);

		execlp("wc", "wc", "-l", NULL);
		_exit(1);
	}
	close(pipes[2][0]);

	for(int filhos= 0; filhos< 4; filhos++){
		if(wait(NULL)< 0){
		perror("Error!\n");
		exit(1);
		}
	}
	return 0;
}