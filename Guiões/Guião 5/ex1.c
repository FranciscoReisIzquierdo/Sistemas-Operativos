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
			close(fd[1]);
			//sleep(5);
			read(fd[0], buffer, sizeof(buffer));
			close(fd[0]);
			printf("Filho: %s\n", buffer);
			_exit(0);
		}
		else{
			close(fd[0]);
			dir= "Teste";
			write(fd[1], dir, sizeof(dir));
			close(fd[1]);
			printf("Pai: %s\n", dir);
		}
	}	
	return 0;
}