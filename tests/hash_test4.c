/* 
 * hash_test4.c --- 
 * 
 * Author: Khaidar Kairbek
 * Created: 10-07-2025
 * Version: 1.0
 * 
 * Description: tests hremove() function
 * 
 */

#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

#include "hash.h"

bool searchfn(void *ep, const void *key) {
	if (*((int *) ep) == 5) return true;

	return false; 
}

void printnodes(void* ep) {
	printf("%d\n", *((int *) ep)); 
}

int main(void) {
	int a = 5;
	int b = 6;
	int c = 7;

	hashtable_t *ht = hopen(10);
	if (ht == NULL) exit(EXIT_FAILURE);
	if (hput(ht, &a, "a", 1) != 0) exit(EXIT_FAILURE);
	if (hput(ht, &b, "ab", 2) != 0) exit(EXIT_FAILURE);
	if (hput(ht, &c, "abc", 3) != 0) exit(EXIT_FAILURE);

	happly(ht, printnodes); 

	int *a_ = hremove(ht, searchfn, "a", 1);
	if (*a_ != 5) exit(EXIT_FAILURE);
	printf("after removing: \n"); 
	happly(ht, printnodes); 
	if (hremove(ht, searchfn, "a", 1) != NULL) exit(EXIT_FAILURE);
	printf("after second remove: \n");
	happly(ht, printnodes); 
	hclose(ht);

	printf("succeeded\n"); 
	
	exit(EXIT_SUCCESS); 
}
