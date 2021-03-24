#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char **argv){
	pid_t pid;
	int status;

	for(int i= 1; i< argc; i++){
		if((pid= fork())== 0){
			printf("Son %d: comando %s\n", getpid(), argv[i]);
			int res= execlp(argv[i], argv[i], NULL);
			printf("Erro\n");
			_exit(res); //Caso dê erro
		}
	}

	for(int i= 1; i< argc; i++){
		pid_t terminated_pid= wait(NULL); //Não me interessa o estado
		printf("Todos os filhos executaram\n");
	}
	return 0;
}