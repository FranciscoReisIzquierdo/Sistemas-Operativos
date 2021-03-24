#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	if(argc< 2){
		printf("Usage program <needle>\n");
		exit(-1);
	}

	pid_t pid;
	int needle= atoi(argv[1]);
	int rows= 10;
	int cols= 10000;
	int rand_max= 10000;
	int status;
	int **matrix;

	printf("Generating numbers from 0 to %d...", rand_max);
	matrix= (int **) malloc(sizeof(int*)* rows);
	for(int i= 0; i< rows; i++){
		matrix[i]= (int*) malloc(sizeof(int)* cols);
		for(int j= 0; j< cols; j++){
			matrix[i][j]= rand() % rand_max;
		}
	}
	printf("Done.\n");

	for(int i= 0; i< rows; i++){
		if((pid= fork()== 0)){
			printf("[pid] %d] row: %d\n", getpid(), i);


			for(int j= 0; j< cols; j++){
				if(matrix[i][j]== needle){
					_exit(i);
				}
			}
			_exit(-1);
		}
	}
	for(int i= 0; i< rows; i++){
		pid_t terminated_pid= wait(&status);
		if(WIFEXITED(status)){
			if(WEXITSTATUS(status)< 255) 
				printf("[pai] process %d exited. Found number at row: %d\n", terminated_pid, WEXITSTATUS(status));
			
			else printf("[pai] process %d exited. Nothing found\n", terminated_pid);
		}
		else{
			printf("[pai] process %d exited. Something went wrong\n", terminated_pid);
		}
	}
	return 0;
}