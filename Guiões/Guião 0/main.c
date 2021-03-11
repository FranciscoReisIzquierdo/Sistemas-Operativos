#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "functions.h"

#define MAX 15
char line[100];
int global_array[MAX]; //Array global

int main(int args, char *argv[]){

	//Array alocado dinamicamente
	int *dynamic_array= malloc(sizeof(int)* MAX);

	//Array Estático
	int static_array[MAX];


	printf("Filling array...\n");
	fill(static_array, MAX, 10);

	printf("Printing array...\n");
	printf("[");
	for(int i= 0; i< MAX; i++){
		if(i< MAX- 1){
			printf("%d", static_array[i]);
			printf(",");
		}
		else{
			printf("%d", static_array[i]);
			printf("]\n");
		} 
	}

	printf("Witch value do you want to search?\n");
	if(!fgets(line, 100, stdin)){
		printf("Error reading value of input\n");
		return 0;
	} 

	line[strcspn(line,"\r\n")] = 0;
	int value= atoi(line);
	printf("Searching in the array...\n");

	int found= find(static_array, MAX, value);
	if(found== -1) printf("Value not found in the array\n");
	else printf("Value found in the position %d\n", found);

	//Search between 2 positions
	printf("Searching in the array between position 2 and 9...\n");
	int begin= 2;
	int end= 9;
	int found2= find(static_array+ begin, MAX- end, value);
	if(found2== -1) printf("Value not found between the positions 2 and 9 of the array\n");
	else printf("Value found between the positions 2 and 9 of the array in the position %d\n", found2);



	return 0;
}