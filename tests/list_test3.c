/* 
 * test3.c --- 
 * 
 * Author: Ava D. Rosenbaum
 * Created: 09-30-2025
 * Version: 1.0
 * 
 * Description: Tests get() fucntion 
 * 
 */

#include <stdlib.h>
#include <stdio.h>
#include "list.h"

int main(void){
	car_t a = {NULL, "123456789", 1.0, 2025};
	car_t b = {NULL, "11111111", 2.0, 2026};
	car_t c = {NULL, "1234556", 3.0, 2027};

	car_t *car;

	car = lget();

	if (car != NULL){ // get() from an empty list
		exit(EXIT_FAILURE);
	}
	
	lput(&a);
	lput(&b);
	lput(&c);

	car = lget(); // get() from a non empty list
	if (car->year != c.year){
		exit(EXIT_FAILURE);
	}

	car = lget();
	if (car->year != b.year){
		exit(EXIT_FAILURE);
	}

	car = lget();
	if (car->year != a.year){
		exit(EXIT_FAILURE);
	}

	exit(EXIT_SUCCESS);
}
		
