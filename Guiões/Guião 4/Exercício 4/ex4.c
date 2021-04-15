#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv){

	if(argc< 4) exit(1);

	int input= -1, output= -1, argumento= 1, fork_ret;

	if(strcmp(argv[argumento], "-i")== 0){
		argumento++;
		input= open(argv[argumento++], O_RDONLY);
	}

	if(strcmp(argv[argumento], "-o")== 0){
		argumento++;
		output= open(argv[argumento++], O_CREAT | O_WRONLY, 0666);
	}

	if(input!= -1) dup2(input, 0);
	if(output!= -1) dup2(output, 1);

	close(input);
	close(output);

	argv[argc]= NULL;

	if((fork_ret= fork())== 0){

		execvp(argv[argumento], argv+ argumento);
		_exit(1);
	}
	else wait(NULL);

	return 0;
}