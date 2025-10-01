/* 
 * queue_test1.c --- 
 * 
 * Author: Ava D. Rosenbaum
 * Created: 09-30-2025
 * Version: 1.0
 * 
 * Description: test qopen(), qput(), and qapply()
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

static double sum = 0;

void sum_salary (void *pp){
	person_t *pp_tmp = (person_t*)pp;
	sum = sum + pp_tmp->rate;
}

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
	person_t p1 = {"Fred", 20, 20.0};
	person_t p2 = {"Ava", 21, 21.0};
	person_t p3 = {"Daniel", 22, 18.5};
	queue_t *qp;

	qp = qopen();

	if (qp == NULL) { // check functionality of qopen()
		printf("Failed to create queue!\n");
		exit(EXIT_FAILURE);
	}

	// check qapply to empty list
	qapply(qp, sum_salary);

	if (sum != 0 ) {
		printf("Failed to sum empty queue\n");
		exit(EXIT_FAILURE);
	}
		
	if (qput(qp, &p1) != 0) {
		printf("Failed to add p1 into queue\n");
		exit(EXIT_FAILURE);
	}

	printf("Added p1 to queue.\n");

	if (qput(qp, &p2) != 0) {
		printf("Failed to add p2 into queue\n");
		exit(EXIT_FAILURE);
	}

	printf("Added p2 to queue.\n");

	if (qput(qp, &p3) != 0) {
		printf("Failed to add p3 into queue\n");
		exit(EXIT_FAILURE);
	}

	printf("Added p3 to queue.\n");

	// check qapply to full list
	qapply(qp, sum_salary);

	if (sum != p1.rate + p2.rate + p3.rate) {
		printf("Failed to apply function\n");
		printf("sum = %f", sum);
		exit(EXIT_FAILURE);
	}
			
	exit(EXIT_SUCCESS);

}

