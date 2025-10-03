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

void print_person (void* personp){
	person_t *p = (person_t *) personp;
	printf("Name: %s, Age: %d, Rate: %.2f \n", p->name, p->age, p->rate);
}

void print_queue(queue_t *qp){
	printf("Queue Contents:\n");
	qapply(qp, print_person);
}


int main(void){
	person_t p1 = {"Fred", 20, 20.0};
	person_t p2 = {"Ava", 21, 21.0};
	person_t p3 = {"Daniel", 22, 18.5};
	person_t *output;
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
	printf("Succesfully did not apply sum to empty queue\n");
		
	if (qput(qp, &p1) != 0) {
		printf("Failed to add p1 into queue\n");
		exit(EXIT_FAILURE);
	}

	printf("Added p1 to queue.\n");
	print_queue(qp);

	if (qput(qp, &p2) != 0) {
		printf("Failed to add p2 into queue\n");
		exit(EXIT_FAILURE);
	}

	printf("Added p2 to queue.\n");
	print_queue(qp);

	if (qput(qp, &p3) != 0) {
		printf("Failed to add p3 into queue\n");
		exit(EXIT_FAILURE);
	}

	printf("Added p3 to queue.\n");
	print_queue(qp);
	
	// check qapply to full list
	qapply(qp, sum_salary);

	if (sum != p1.rate + p2.rate + p3.rate) {
		printf("Failed to apply function\n");
		printf("sum = %f", sum);
		exit(EXIT_FAILURE);
	}

	// remove all nodes:
	output = qget(qp);
	printf("Removing: %s\n", output->name);
	output = qget(qp);
	printf("Removing: %s\n", output->name);	
	output = qget(qp);
	printf("Removing: %s\n", output->name);	
	
	qclose(qp); // free up memory
	
	exit(EXIT_SUCCESS);

}

