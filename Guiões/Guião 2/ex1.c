#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main(int agrc, char *argv[]){
	
	pid_t pid_atual= getpid();
	pid_t pid_pai= getppid();

	printf("Pid do processo atual: %d. Pid do processo pai: %d\n", pid_atual, pid_pai);

	return 0;
}