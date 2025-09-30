/* 
 * test2.c --- 
 * 
 * Author: Khaidar Kairbek
 * Created: 09-28-2025
 * Version: 1.0
 * 
 * Description: Tests apply() function.  
 * 
 */
#include <stdlib.h>
#include <stdio.h>
#include "list.h"

static int sum = 0; 

void f(car_t *cp) {
	sum += cp->year;  
}

int main() {
	car_t a = {NULL, "123456789", 2.0, 2025};
	car_t b = {NULL, "123456789", 3.0, 2026};
	car_t c = {NULL, "123456789", 4.0, 2027};

	lapply(f);
	if (sum != 0) exit(EXIT_FAILURE); 
	
	lput(&a);
	lput(&b);
	lput(&c);

	lapply(f);
	if (sum != (2025 + 2026 + 2027)) exit(EXIT_FAILURE);

	exit(EXIT_SUCCESS); 
}
