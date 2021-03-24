#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main(int agrc, char *argv[]){

	pid_t pid;

	//Processo filho
	if((pid= fork())== 0){
		pid= getpid();
		pid_t pid_pai= getppid();
		printf("Processo Filho: Pid do processo: %d. Pid do processo pai: %d\n", (int) pid, (int) pid_pai);
	}
	//Processo pai
	else{
		wait(NULL);
		pid_t pid_atual= getpid();
		pid_t pid_pai= getppid();
		printf("Processo Pai: Pid do processo: %d. Pid do processo pai: %d. Pid do processo filho: %d\n", (int) pid_atual, (int) pid_pai, (int) pid);
	}
	return 0;
}