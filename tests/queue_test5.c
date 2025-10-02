/* 
 * queue_test5.c --- 
 * 
 * Author: Khaidar Kairbek
 * Created: 10-02-2025
 * Version: 1.0
 * 
 * Description: tests qsearch()
 * 
 */

#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

bool searchfn(void *elementp, const void *keyp) {
	int *e = (int *) elementp;
  const int *key = (int *) keyp; 
	printf("Value: %d, Key: %d\n", *e, *key);
	return *e == *key; 
}

int main() {
	queue_t *qp = qopen();
	int value1, value2, value3;
	value1 = 1;
	value2 = 2;
	value3 = 3;

	int key = 3;
	int key2 = 5; 

	if (qp == NULL) exit(EXIT_FAILURE);
	// empty queue search
	if (qsearch(qp, searchfn, &key) != NULL) exit(EXIT_FAILURE);
	
	qput(qp, &value1);
	qput(qp, &value2);
	qput(qp, &value3);

	// filled queue search with valid key
	if (qsearch(qp, searchfn, &key) != &value3) exit(EXIT_FAILURE);
	// filled queue search with wrong key
	if (qsearch(qp, searchfn, &key2) != NULL) exit(EXIT_FAILURE);

	int value33 = 3;

	qput(qp, &value33);

	if (qsearch(qp, searchfn, &key1) != &value3) exit(EXIT_FAILURE);

	exit(EXIT_SUCCESS); 
}
