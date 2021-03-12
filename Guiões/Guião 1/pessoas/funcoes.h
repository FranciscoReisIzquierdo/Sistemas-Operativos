#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define FILENAME "file_pessoas"

typedef struct P{
	char name [200];
	int age;
}Person;

int list();

int new_person(char *name, int age);

int person_change_age(char *name, int age);

int person_change_age_v2(long pos, int age);