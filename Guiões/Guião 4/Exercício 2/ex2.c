#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>


int main(int argc, char **argv){

	int res= 0;

	int i_fd= open("/etc/passwd", O_RDONLY);
	int o_fd= open("saida.txt", O_CREAT | O_WRONLY, 0666);
	int e_fd= open("erros.txt", O_CREAT | O_WRONLY, 0666);

	//Descritores de backup
	int std_in= dup(0);
	int std_out= dup(1);
	int errors= dup(2);

	res= dup2(i_fd, 0);
	res= dup2(o_fd, 1);
	res= dup2(e_fd, 2);

	close(i_fd);
	close(o_fd);
	close(e_fd);

	pid_t pid= -1;

	if((pid= fork())== 0){
		//int processo= getpid();
		char string[]= "Processo Filho\n";
		write(std_out, string, strlen(string)+ 1);



		int n_lines= 10;
		char buffer;
		char line[1024];
		int i= 0;

		while(n_lines> 0){
			while(read(0, &buffer, 1)!= 0){
				line[i++]= buffer;

				if(buffer== '\n') break;
			}
			write(1, line, i);
			write(2, line, i);
			i= 0;
			n_lines--;
		}
		_exit(0);
	}
	else{
		dup2(std_in, 0);
		dup2(std_out, 1);
		dup2(errors, 2);

		pid_t terminated_pid= wait(NULL); 
		char string[]= "Todos os filhos executaram\n";
		write(1, string, strlen(string)+ 1);
	}

	return 0;
}