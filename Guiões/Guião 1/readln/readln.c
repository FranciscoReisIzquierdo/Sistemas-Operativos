#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

ssize_t readln(int fd, char *line, size_t size){

	ssize_t res= 0;
	ssize_t i= 0;
	int indice, count;

	while((res= read(fd, &line[i], size))> 0){

		for(indice= i, count= 0; count< size && ((char*) line)[indice]!= '\n'; count++, indice++);
		if(count== size) i+= res;
		else{
			i+= count;
			return i;
		} 
	} 
	return i;
}


int main(int args, char *argv[]){
	if(args< 2){
		printf("Missing source file\n");
		return -1;
	}

	size_t size= 1; //Lê apenas 1 byte de cada vez

	if(args> 2) size= atoi(argv[2]); //Lê o tamanho de bytes predefinido pelo utilizador

	int original_file= open(argv[1], O_RDONLY);
	if(original_file< 0){
		printf("File or directory %s does not exist\n", argv[1]);
		return 0;
	}
	char buffer[100];

	ssize_t result= readln(original_file, buffer, size);
	write(1, &buffer, result);
	putchar('\n');
	close(original_file);
	return 1;
}