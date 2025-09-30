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
#include <stdint.>
#include <string.h>
#include <stddef.h>
#include <stdlib.h>

// create an empty queue
queue_t* qopen(void){ 

}

// deallocate a queue, frees everything in it
void qclose(queue_t *qp){

}

// put element at end of queue
int32_t qput (queue_t *qp, void *elementp){


}

// get the first element from queue, remove it
void* qget(queue_t *qp){


}

// apply a function to every element of the queue
void qapply (queue *qp, void (*fn)(void* elementp)) {

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
