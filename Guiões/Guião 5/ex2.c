#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(){

	int fd[2];

	int status= pipe(fd);

	if(status< 0){
		perror("Erro!\n");
		return -1;
	}
	else{
		char buffer[5];
		char *dir;
		size_t pt;

		if((pt= fork())== 0){
			int status;
			close(fd[1]);
			while(status= read(fd[0], buffer, sizeof(buffer))!= 0);
			close(fd[0]);
			printf("Filho: %s\n", buffer);
			_exit(0);
		}
		else{
			close(fd[0]);
			dir= "Teste";
			size_t size_of_dir= 5;
			write(fd[1], dir, size_of_dir);
			close(fd[1]);
			printf("Pai: %s\n", dir);
		}
	}
	return 0;
}

