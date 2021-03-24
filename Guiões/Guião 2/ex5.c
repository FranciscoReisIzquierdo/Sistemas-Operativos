#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main(int agrc, char *argv[]){
	int level= 1;
	pid_t pid;

	for(int level= 0; level< 11; level++){
		pid_t atual= getpid();
		pid_t pai= getppid();
		printf("Nivel do Processo: %d. Pid do processo: %d. Pid do pai: %d\n", level, (int) atual, (int) pai);
		if(fork()){
			int status= wait(&status);
			_exit(status);
		} 
	}

	return 0;
}