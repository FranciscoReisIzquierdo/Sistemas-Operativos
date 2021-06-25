#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <signal.h>

size_t number_of_ctrl_C= 0;
size_t tempo= 0;

void sig_handler_ctrl_C(int signum){
	printf("Tempo passado: %zu\n (segundos)", tempo);
	number_of_ctrl_C++;
}

void sig_handler_ctrl_barra(int signum){
	printf("Numero de ctrl+ C: %zi\n", number_of_ctrl_C);
	exit(0);
}

void sig_handler_alrm(int signum){
	tempo++;
	alarm(1);
}



int main(int agrc, char **agrv){
	if((signal(SIGINT, sig_handler_ctrl_C))== SIG_ERR){
		perror("Error with SIGINT\n");
		exit(0);
	}
	if((signal(SIGQUIT, sig_handler_ctrl_barra))== SIG_ERR){
		perror("Error with SIGQUIT\n");
		exit(0);
	}
	if((signal(SIGALRM, sig_handler_alrm))== SIG_ERR){
		perror("Error with SIGALRM\n");
		exit(0);
	}

	alarm(1);
	while(1);
	return 0;
}