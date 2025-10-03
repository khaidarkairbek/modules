/* 
 * queue_test2.c --- 
 * 
 * Author: Ava D. Rosenbaum
 * Created: 09-30-2025
 * Version: 1.0
 * 
 * Description: tests qconcat()
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
	person_t p4 = {"John", 52, 13};
	person_t p5 = {"Sarah", 80, 33};
	
	queue_t *q1, *q2;

	person_t *output;

 	q1 = qopen();
	q2 = qopen();

	// test concatting two empty queues
	printf("Testing empty q1 + empty q2\n");
	qconcat(q1, q2);
	print_queue(q1);
	
	output = qget(q1);
	if (output != NULL) {
		exit(EXIT_FAILURE);
	}
	printf("Both q1 & q2 empty PASSES!\n");

	q2 = qopen(); // must reopen q2 because qconcat frees it
	
	// test concatting q1 with empty queue
 	qput(q1, &p1);
	qput(q1, &p2);
	qput(q1, &p3);

	printf("Testing q1 + empty q2\n");
	qconcat(q1, q2);
	print_queue(q1);
	
	output = qget(q1); // gets first element and removes
	if (output != &p1) {
		exit(EXIT_FAILURE);
	}

	output = qget(q1); // gets next element and removes
	if (output != &p2) {
		exit(EXIT_FAILURE);
	}
	
	output = qget(q1); // gets last element and removes 
	if (output != &p3) {
		exit(EXIT_FAILURE);
	}

	printf("q1 nonempty & q2 empty PASSES!\n");

	qclose(q1); // free up empty queue

	// reopen queues
	q1 = qopen(); 
	q2 = qopen();
	
	// test concatting q2 with empty queue
	printf("Testing empty q1 + nonempty q2\n");
	qput(q2, &p1);
	qput(q2, &p2);
	qput(q2, &p3);

	qconcat(q1, q2);
	print_queue(q1);
	
	output = qget(q1);
	if (output != &p1) {
		exit(EXIT_FAILURE);
	}

	output = qget(q1);
	if (output != &p2) {
		exit(EXIT_FAILURE);
	}
	output = qget(q1);
	if (output != &p3) {
		exit(EXIT_FAILURE);
	}

	qclose(q1);
	
	printf("q1 empty & q2 nonempty PASSES!\n");

	q1 = qopen();
	q2 = qopen();
	
	// test concatting q1 & q2, both nonempty
	printf("Testing both nonempty q1 + q2\n");
	qput(q1, &p1);
	qput(q1, &p2);
	qput(q1, &p3);
	qput(q2, &p4);
	qput(q2, &p5);

	qconcat(q1, q2);
	print_queue(q1);

	output = qget(q1);
	if (output != &p1) {
		exit(EXIT_FAILURE);
	}

	output = qget(q1);
	if (output != &p2) {
		exit(EXIT_FAILURE);
	}
	
	output = qget(q1);
	if (output != &p3) {
		exit(EXIT_FAILURE);
	}

	output = qget(q1);
	if (output != &p4) {
		exit(EXIT_FAILURE);
	}
	output = qget(q1);
	if (output != &p5) {
		exit(EXIT_FAILURE);
	}
	printf("q1 nonempty & q2 nonempty PASSES!\n");

	qclose(q1);
	
	exit(EXIT_SUCCESS);
}
	
	
