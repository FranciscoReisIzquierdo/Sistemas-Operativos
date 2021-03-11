#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

void fill(int* vector, int size, int value){
	for(int i= 0; i< size; vector[i++]= value);
}

int find(int* vector, int size, int value){
	for(int i= 0; i< size; i++) if(value== vector[i]) return i;
	return -1;
}