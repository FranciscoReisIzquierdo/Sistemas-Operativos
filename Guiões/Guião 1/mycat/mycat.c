#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

int main(char *argv[], int argc){
	char *byte;
	ssize_t res;
	while(res= read(0, &byte, 1) != 0){
		write(1, &byte, res);
	}
	return 0;
}