#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int args, char *argv[]){
	if(args< 2){
		printf("Missing source file\n");
		return -1;
	}
	else if(args< 3){
		printf("Missing destination file\n");
		return 0;
	}

	int size= 100;

	if(args== 4) size= atoi(argv[3]); //Tamanho do buffer


	int original_file= open(argv[1], O_RDONLY);
	if(original_file< 0){
		printf("File or directory %s does not exist\n", argv[1]);
		return 1;
	}
	
	int copy_file= open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	char *buffer= malloc(sizeof(char)* size);
	ssize_t bytes;

	while(bytes= read(original_file, buffer, size)!= 0) write(copy_file, buffer, size);

	close(original_file);
	close(copy_file);
	return 2;
}