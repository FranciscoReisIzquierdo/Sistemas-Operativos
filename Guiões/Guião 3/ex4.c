#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char **argv){

	argv[0]= "EX3";
	int ret= execv("./ex3", argv);


	printf("Result: %d\n", ret);
	return 0;
}