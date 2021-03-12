#include <stdlib.h>
#include <stdio.h>
#include "funcoes.h"

int main(int argc, char *argv[]){
	char id[20]= "";
		if(strcmp(argv[1], "-i")== 0){
			int res= new_person(argv[2], atoi(argv[3]));
			snprintf(id, 20, "registo %d\n", res);
			write(1, id, sizeof(id));
		}
		else if(strcmp(argv[1], "-u")== 0){
			person_change_age(argv[2], atoi(argv[3]));
		}
		else if(strcmp(argv[1], "-o")== 0){
			person_change_age_v2(atoi(argv[2]), atoi(argv[3]));
		}
		else if(strcmp(argv[1], "-l")== 0){
			list();
		}
		return 0;
}