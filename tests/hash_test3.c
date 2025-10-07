/* 
 * hash_test3.c --- 
 * 
 * Author: Khaidar Kairbek
 * Created: 10-07-2025
 * Version: 1.0
 * 
 * Description: tests happly() function
 * 
 */
#include <stdlib.h>
#include <stdio.h>

#include "hash.h"

static int sum = 0; 

void fn(void *ep) {
	int *value = (int *) ep;

	sum += *value;
	printf("%d\n", *value); 
}

int main(void) {
	int a = 5;
	int b = 6;
	int c = 7;

	hashtable_t *ht = hopen(10);
	if (hput(ht, &a, "a", 1) != 0) exit(EXIT_FAILURE);
	if (hput(ht, &b, "ab", 2) != 0) exit(EXIT_FAILURE);
	if (hput(ht, &c, "abc", 3) != 0) exit(EXIT_FAILURE);
	
	happly(ht, fn);
	if (sum != (a + b + c)) exit(EXIT_FAILURE);

	hclose(ht); 
	
	exit(EXIT_SUCCESS); 
}
