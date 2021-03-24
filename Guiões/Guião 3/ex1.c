#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char **argv){
	int ret;

	//ret= execl("/bin/ls", "ls", "-l", NULL);

	//ret= execlp("ls", "ls", "-l", NULL);

	char *exargs[]= {"ls", "-l", NULL};

	//ret= execv("/bin/ls", exargs);

	ret= execvp("ls", exargs);

	printf("Done\n");

	return 0;
}