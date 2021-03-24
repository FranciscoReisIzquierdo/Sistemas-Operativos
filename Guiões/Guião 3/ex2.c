#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char **argv){

	int ret, pid, status;
	if((pid= fork())== 0){

		printf("SON: %d\n", getpid());
		char *exargs[]= {"ls", "-l", NULL};
		ret= execvp("ls", exargs);
		_exit(ret);
	}

	else{
		printf("FATHER: %d\n", getpid());
		pid_t terminated= wait(&status);

		if(WIFEXITED(status)){
			printf("Filho terminou %d st= %d\n", terminated, WEXITSTATUS(status));
		}
		else printf("ERROR\n");
	}

	printf("Done\n");
	return 0;
}