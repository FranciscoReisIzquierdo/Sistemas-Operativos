#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char **argv){

	int res= 0;

	int i_fd= open("/etc/passwd", O_RDONLY);
	int o_fd= open("saida.txt", O_CREAT | O_WRONLY, 0666);
	int e_fd= open("erros.txt", O_CREAT | O_WRONLY, 0666);

	//Redirecionamento dos descritores
	res= dup2(i_fd, 0);
	res= dup2(o_fd, 1);
	res= dup2(e_fd, 2);

	execlp("wc", "wc", NULL);
	exit(1);

	return 0;


}

