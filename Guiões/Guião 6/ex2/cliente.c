#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

int main(int agrc, char **agrv){

	int file_pointer, status;
	char buffer[BUFFER_SIZE];
	int bytes;
	if((file_pointer= open("fifo", O_WRONLY))< 0){
		perror("Error\n");
		exit(1);
	}

	else{
		printf("Fifo aberto para escrita\n");
		while((bytes= read(0, buffer, BUFFER_SIZE))> 0){
			status= write(file_pointer, buffer, bytes);
			if(status== -1) perror("Error\n");
		}
			
	}
	close(file_pointer);
	return 0;
}