/* 
 * queue_test1.c --- 
 * 
 * Author: Ava D. Rosenbaum
 * Created: 09-30-2025
 * Version: 1.0
 * 
 * Description: test qopen()
 * 
 */

#include <queue.h>

#define NAMELEN 20

typedef struct person {
	struct person *next;
	char name[NAMELEN];
	int age;
	double rate;
} person_t;

static person_t *front = NULL;
static person_t *back = NULL;

person_t *make_person(char *name, int age, double rate){
	person_t *pp;
	if (!(pp = (person_t*)) malloc (sizeof (person_t))) {
		printf("error: malloc failed allocating person\n");
		return NULL;
	}
	pp->next = NULL;
	strcpy(pp->name, name);
	pp->age = age;
	pp->rate = rate;
	return pp;
}

int main(void){
	person_t *pp;
	queue_t *qp;

	qp = qopen();
	pp = make_person("Fred", 20, 20.0);
	qput(qp, (void*)pp);

}

