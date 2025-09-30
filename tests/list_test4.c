/* 
 * test4.c --- 
 * 
 * Author: Ava D. Rosenbaum
 * Created: 09-30-2025
 * Version: 1.0
 * 
 * Description: test remove() function 
 * 
 */

#include <stdlib.h>
#include <stdio.h>
#include "list.h"

static car_t *front = NULL;

int main(void){
	car_t a = {NULL, "111111", 1.0, 2025};
	car_t b = {NULL, "222222", 2.0, 2026};
	car_t c = {NULL, "333333", 2.0, 2027};
	int length=0;
	car_t *curr = front;
	
	car_t *car;

	car = lremove(a.plate);

	if (car != NULL) {
		exit(EXIT_FAILURE);
	}

	lput(&a);
	lput(&b);
	lput(&c);

	car = lremove(a.plate); // remove from a non-empty list at the end

	if (car->year != a.year){
		exit(EXIT_FAILURE);
		
		while (curr != NULL) {
			length++;
			curr = curr->next;
		}
		if (length != 2){
			exit(EXIT_FAILURE);
		}
	}

	lput(&a);

	car = lremove(a.plate); // remove from a non-empty list at the beginning

	if (car->year != a.year){
		exit(EXIT_FAILURE);

		while (curr != NULL) {
			length++;
			curr = curr->next;
		}
		if (length != 2){
			exit(EXIT_FAILURE);
		}
	}


	lput(&a);

	car = lremove(c.plate); // remove from a non-empty list in the middle
	
	if (car->year != c.year){
		exit(EXIT_FAILURE);

		while (curr != NULL) {
			length++;
			curr = curr->next;
		}
		if (length != 2){
			exit(EXIT_FAILURE);
		}
	}

	
	exit(EXIT_SUCCESS);
}
