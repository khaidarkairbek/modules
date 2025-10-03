/* 
 * queue_test2.c --- 
 * 
 * Author: Ava D. Rosenbaum
 * Created: 09-30-2025
 * Version: 1.0
 * 
 * Description: tests qget()
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
	queue_t *qp;

	person_t *output;

 	qp = qopen();

	output = qget(qp);

	if (output != NULL){ // checks again if empty
		exit(EXIT_FAILURE);
	}
	printf("Successfully qget on empty list\n");

	qput(qp, &p1);
	qput(qp, &p2);
	qput(qp, &p3);

	printf("Filled queue with 3 people:\n");
	print_queue(qp);

	output = qget(qp);
	
	if (output->age != p1.age){
		exit(EXIT_FAILURE);
	}
	printf("%s removed from the queue!\n", output->name);

	printf("People Remaining:\n");
	print_queue(qp);
	
	output = qget(qp);

	if (output->age != p2.age){
		exit(EXIT_FAILURE);
	}
	printf("%s removed from the queue!\n", output->name);

	printf("People Remaining:\n");
	print_queue(qp);
	
	output = qget(qp);

	if (output->age != p3.age){
		exit(EXIT_FAILURE);
	}
	printf("%s removed from the queue!\n", output->name);

	printf("People Remaining:\n");
	print_queue(qp);
	
	output = qget(qp);
	
	if (output != NULL){ // checks again if empty
		exit(EXIT_FAILURE);
	}

	printf("No more people in the queue!\n");
	qclose(qp);
	exit(EXIT_SUCCESS);
}
	
	
