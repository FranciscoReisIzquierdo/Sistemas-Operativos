#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int agrc, char **agrv){
	if(mkfifo("fifo", 0644)== -1){
		perror("mkfifo");
	}
	else{
		printf("Pipe FIFO criado com sucesso\n");
	}
	return 0;
}