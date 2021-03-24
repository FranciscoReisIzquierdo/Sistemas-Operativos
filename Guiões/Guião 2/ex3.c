#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main(int agrc, char *argv[]){
	pid_t pid;

	for(int i= 1; i<= 10; i++){
		if((pid= fork())== 0){
			pid_t filho= getpid();
			pid_t pai= getppid();
			printf("Processo Filho %d: Pid do processo: %d. Pid do pai: %d\n", i, (int) filho, (int) pai);
			_exit(i);
		}
		else{
			int status;
			wait(&status);
			printf("Processo pai: Codigo de saida: %d\n", WEXITSTATUS(status));
		}
	} 
	return 0;
}