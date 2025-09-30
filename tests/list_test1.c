/* 
 * test1.c --- 
 * 
 * Author: Khaidar Kairbek
 * Created: 09-28-2025
 * Version: 1.0
 * 
 * Description: Tests put() function 
 *
 */

#include "list.h"
#include <stdlib.h>

int main() {
	car_t a = {NULL, "123456789", 1.0, 2025};
	if (lput(&a) != 0) exit(EXIT_FAILURE);
	car_t b = {NULL, "123456789", 2.0, 2026};
	if (lput(&b) != 0) exit(EXIT_FAILURE);

	exit(EXIT_SUCCESS); 
}
