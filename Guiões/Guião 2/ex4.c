#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main(int agrc, char *argv[]){
	pid_t pid;

	for(int i= 1; i<= 10; i++){
		if((pid= fork())== 0) _exit(i);
	}

	int status;
	while(wait(&status)!= -1) printf("Codigo de saida do processo filho: %d\n", WEXITSTATUS(status));
	
	return 0;
}