#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

int main(int agrc, char **agrv){
	if(mkfifo("fifo", 0644)== -1){
		perror("mkfifo");
	}

	int file_pointer, status;
	char buffer[BUFFER_SIZE];
	int bytes;

	while(1){
		if((file_pointer= open("fifo", O_RDONLY))< 0){
		perror("Error\n");
		exit(1);
		}
		else{
			printf("Fifo aberto para leitura\n");
			while((bytes= read(file_pointer, buffer, BUFFER_SIZE))> 0)
			write(1, buffer, bytes);
		}
		close(file_pointer);
	}
	unlink("fifo");

	return 0;

}