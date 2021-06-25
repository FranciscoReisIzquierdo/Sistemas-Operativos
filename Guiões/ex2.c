#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <signal.h>

int main(int agrc, char **agrv){
	if(argc < 3) {
        puts("Usage: multigrep <palavra> <file> ...");
        return 5;
    }

    //Criamos tantos filhos (forks) quantos files temos
    int number_files= argc- 2;
    char **files= argv+ 2;
    pid_t pid;
    int pids[number_files];
    for(int filho= 0; filho< number_files; i++){
    	pid_t pid= -1;
    	if((pid= fork())== 0) printf("Filho %d com pid %d a executar\n", i, getpid());

    	if((execlp("grep", "grep", argv[1], files[i], NULL))< 0){
    		perror("Error in grep\n");
    		exit(2);
    	}
    	pids[i]= pid; //O pai guarda o pid do processo filho criado
    }
    int status;
    wait(&status);
    if(status== 0){
    	for(int i= 0; i< number_files; i++){
    		kill(pids[i], SIGKILL);
    	}
    }
    
}