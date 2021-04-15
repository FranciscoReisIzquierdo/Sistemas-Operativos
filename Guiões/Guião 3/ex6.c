#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>


int my_system(char *command){

	int fork_ret, exec_ret, wait_ret, status, res;

	char *exec_args[1024];
	char *string;
	int i= 0;

	string= strtok(command, " ");

	while(string!= NULL){

		exec_args[i]= string;
		string= strtok(NULL, " ");
		i++;
	}
		
	exec_args[i]= NULL;

	
	fork_ret= fork();

	if(fork_ret== 0){

		exec_ret= execvp(exec_args[0], exec_args);
		_exit(exec_ret);
	}

	else{
		if(fork_ret!= -1){

			wait_ret= wait(&status);

			if(WIFEXITED(status)) res= WEXITSTATUS(status);

			else res= -1;
		}
		else res= -1;
	}

	return res;
}


int main(int argc, char **argv){

	char command[1024];
	printf("Insira o nome do executavel+ argumentos\n");
	fgets(command, 1024, stdin);

	command[strcspn(command, "\n\r")]= 0;

	int result= my_system(command);

	return 0;
}