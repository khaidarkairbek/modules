/* 
 * hash_test2.c --- 
 * 
 * Author: Ava D. Rosenbaum
 * Created: 10-07-2025
 * Version: 1.0
 * 
 * Description: test hsearch
 * 
 */

#include <stdlib.h>
#include "hash.h"
#include <stdio.h>
#include <string.h>
#define NAMELEN 20

typedef struct person {
	char name[NAMELEN];
	int age;
	double rate;
} person_t;

void print_person (void* personp){
	person_t *p = (person_t *) personp;
	printf("Name: %s, Age: %d, Rate: %.2f \n", p->name, p->age, p->rate);
}

void print_hash(hashtable_t *htp){
	printf("Hash Contents:\n");
	happly(htp, print_person);
}

bool searchfn(void *elementp, const void *keyp) {
	person_t *p = (person_t *) elementp;
	const char *key = (const char *) keyp;
	printf("Key: %s\n", key);
	print_person(p);
	return strcmp(p->name, key) == 0;
}

int main(void) {
	hashtable_t *htp;
	person_t p1 = {"Fred", 20, 20.0};
	person_t p2 = {"Ava", 21, 21.0};
	person_t p3 = {"Daniel", 22, 18.5};

	person_t *found;
	
	htp = hopen(10);

	if (hput(htp, &p1, p1.name, strlen(p1.name)) != 0) {
		printf("Failed to add p1 into hashtable\n");
		exit(EXIT_FAILURE);
	}
	printf("Successfully added p1 into hashtable:\n");

	if (hput(htp, &p2, p2.name, strlen(p2.name)) != 0) {
		printf("Failed to add p2 into hashtable\n");
		exit(EXIT_FAILURE);
	}
	printf("Successfully added p2 into hashtable:\n");

	if (hput(htp, &p3, p3.name, strlen(p3.name)) != 0) {
		printf("Failed to add p3 into hashtable\n");
		exit(EXIT_FAILURE);
	}
	printf("Successfully added p3 into hashtable:\n");
	print_hash(htp);

	found = hsearch(htp, searchfn, p1.name, strlen(p1.name)); // search for a valid key

	if (found == NULL){
		printf("Failed to find p1\n");
		exit(EXIT_FAILURE);
	}
	printf("Found p1!\n");

	found = hsearch(htp, searchfn, "test", strlen("test"));

	if (found != NULL){
		printf("Failed to unsuccessfully find invalid key\n");
		exit(EXIT_FAILURE);
	}
	printf("Successfully did not find invalid key!\n");

	hclose(htp);

	exit(EXIT_SUCCESS);
}
	
	
	
