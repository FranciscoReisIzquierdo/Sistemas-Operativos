#include <stdio.h>
#include <string.h>
#include "readln.h"

typedef ssize_t (*funcs[2])(int fd, char* line, size_t size);
funcs readlns = {readln, readln2};

int main(int argc, char const *argv[]) {

    char line[1024];
    int file;
    if(argc< 2) file = 0;

    else file = open(argv[1], O_RDONLY);
    if(file< 0){
		printf("File or directory %s does not exist\n", argv[1]);
		return -1;
	}

    int mode = 1;
    if(argc > 2) {
        mode = atoi(argv[2]) - 1;
    }

    size_t size;

    
    int i = 1;
    while((size = readlns[mode](file, line, 1024))) {
        char lineno[100];
        sprintf(lineno, "%*d  ", 6, i++);
        write(STDOUT_FILENO, lineno, strlen(lineno));
        write(STDOUT_FILENO, line, size);
    }

    close(file);
    return 0;
}

