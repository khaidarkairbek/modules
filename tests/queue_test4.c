/* 
 * queue_test4.c --- 
 * 
 * Author: Khaidar Kairbek
 * Created: 10-02-2025
 * Version: 1.0
 * 
 * Description: tests qclose() 
 * 
 */
#include <stdlib.h>
#include "queue.h"

int main(void) {
	queue_t *q = qopen();
	
	if (q == NULL) exit(EXIT_FAILURE);

	qclose(q);

	exit(EXIT_SUCCESS); 
}
