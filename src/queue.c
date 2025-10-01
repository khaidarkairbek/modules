/* 
 * queue.c --- 
 * 
 * Author: Ava D. Rosenbaum, Khaidar Kairbek
 * Created: 09-30-2025
 * Version: 1.0
 * 
 * Description: Implementation of a queue
 * 
 */

#include "queue.h"
#include <stdint.h>
#include <string.h>
#include <stddef.h>
#include <stdlib.h>

typedef struct node {
	void *data; // node for any data
	struct node *next;
} node_t;

typedef struct queue {
	node_t *front;
	node_t *back;
} queue_list_t;

// create an empty queue
queue_t* qopen(void){ 
	queue_list_t *qp = malloc (sizeof (queue_list_t)); // allocate memory
	if (!qp) {
		return NULL;
	}
	qp->front = NULL;
	qp->back = NULL;
	return (queue_t *)qp; // cast to queue_t type
}
	

// deallocate a queue, frees everything in it
void qclose(queue_t *qp){

}

// put element at end of queue
int32_t qput (queue_t *qp, void *elementp){
	queue_list_t *qp_tmp = (queue_list_t *) qp;
	node_t *p = malloc (sizeof (node_t));
	
	if (!qp) { // checks if pointer is valid
		return 1;
	}

	if (!p) {
		return 1;
	}

	p->data = elementp;
	p->next = NULL; // put at the end of the list

	if (qp_tmp->back != NULL){
		qp_tmp->back->next = p; // if queue not empty, put new element in the back
		qp_tmp->back = p;
	}
	else { // if queue is empty, set front and back to new element
		qp_tmp->front = p;
		qp_tmp->back = p;
	}
	return 0;
}

// get the first element from queue, remove it
void* qget(queue_t *qp){
	if (!qp) return NULL; // invalid queue
	
	queue_list_t *qp_tmp = (queue_list_t *) qp;

	if (!qp_tmp->front) return NULL; // empty queue

	node_t *first = qp_tmp->front;
	void *data = first->data;


	

	qp_tmp->front = first->next; // set new front to next in line
	if (!qp_tmp->front) { // if queue is now empty, set back to NULL
		qp_tmp->back = NULL;
	}

	free(first);
	return(data);

}

// apply a function to every element of the queue
void qapply (queue_t *qp, void (*fn)(void* elementp)) {
	queue_list_t *qp_tmp = (queue_list_t *) qp;
	node_t *curr;

	if (!qp){
		return;
	}
	
	for (curr = qp_tmp->front; curr != NULL; curr = curr->next){
		fn(curr->data);
	}
	
}

// search a queue using a supplied boolean function
void* qsearch (queue_t *qp, bool (*searchfn)(void* elementp, const void* keyp), const void* skeyp){

}

//searches a queue using a supplied boolean function,
// removes the element and returns a pointer to it
void* qremove(queue_t *qp, bool (*searchfn)(void* elementp, const void* keyp), const void* skeyp){

}

// concatenates elements of q2 into q1
void qconcat(queue_t *q1p, queue_t *q2p){


}
