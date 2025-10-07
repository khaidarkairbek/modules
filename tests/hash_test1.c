/* 
 * hash_test1.c --- 
 * 
 * Author: Ava D. Rosenbaum
 * Created: 10-06-2025
 * Version: 1.0
 * 
 * Description: test hclose, hput
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

int main(void) {
	hashtable_t *htp;
	person_t p1 = {"Fred", 20, 20.0};
	person_t p2 = {"Ava", 21, 21.0};
	person_t p3 = {"Daniel", 22, 18.5};

	htp = hopen(10);

	if (htp == NULL) { // check functionality of qopen()
		printf("Failed to create hashtable!\n");
		exit(EXIT_FAILURE);
	}
	printf("Successfully created hashtable!\n");
	print_hash(htp);
	
	if (hput(htp, &p1, p1.name, strlen(p1.name)) != 0) {
		printf("Failed to add p1 into hashtable\n");
		exit(EXIT_FAILURE);
	}
	printf("Successfully added p1 into hashtable:\n");
	print_hash(htp);
	
	if (hput(htp, &p2, p2.name, strlen(p2.name)) != 0) {
		printf("Failed to add p2 into hashtable\n");
		exit(EXIT_FAILURE);
	}
	printf("Successfully added p2 into hashtable:\n");
	print_hash(htp);

	if (hput(htp, &p3, p3.name, strlen(p3.name)) != 0) {
		printf("Failed to add p3 into hashtable\n");
		exit(EXIT_FAILURE);
	}
	printf("Successfully added p3 into hashtable:\n");
	print_hash(htp);

	print_hash(htp);

	hclose(htp);
	printf("Hashtable closed successfully\n");
	exit(EXIT_SUCCESS);
	
}
