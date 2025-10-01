/* 
 * queue_test1.c --- 
 * 
 * Author: Ava D. Rosenbaum
 * Created: 09-30-2025
 * Version: 1.0
 * 
 * Description: test qopen()
 * 
 */

#include <stdlib.h>
#include <queue.h>
#include <stdio.h>
#include <string.h>
#define NAMELEN 20

typedef struct person {
	char name[NAMELEN];
	int age;
	double rate;
} person_t;


person_t *make_person(char *name, int age, double rate){
	person_t *pp;
	if (!(pp = (person_t*) malloc (sizeof (person_t)))) {
		printf("error: malloc failed allocating person\n");
		return NULL;
	}
	strcpy(pp->name, name);
	pp->age = age;
	pp->rate = rate;
	return pp;
}

int main(void){
	person_t *p1, *p2, *p3;
	queue_t *qp;

	qp = qopen();

	if (qp == NULL) { // check functionality of qopen()
		printf("Failed to create queue!\n");
		exit(EXIT_FAILURE);
	}
	
	p1 = make_person("Fred", 20, 20.0);
	p2 = make_person("Ava", 21, 21.0);
	p3 = make_person("Daniel", 22, 18.5);

	if (!p1 || !p2 || !p3 ){
		printf("Failed to allocate people\n");
		exit(EXIT_FAILURE);
	}

	if (qput(qp, (void*)p1) != 0) {
		printf("Failed to add p1 into queue\n");
		exit(EXIT_FAILURE);
	}

	printf("Added p1 to queue.\n");

	if (qput(qp, (void*)p2) != 0) {
		printf("Failed to add p2 into queue\n");
		exit(EXIT_FAILURE);
	}

	printf("Added p2 to queue.\n");

	if (qput(qp, (void*)p3) != 0) {
		printf("Failed to add p3 into queue\n");
		exit(EXIT_FAILURE);
	}

	printf("Added p3 to queue.\n");

	free(p1);
	free(p2);
	free(p3);
	
	exit(EXIT_SUCCESS);

}

