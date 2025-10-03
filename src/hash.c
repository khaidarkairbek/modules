/* 
 * hash.c -- implements a generic hash table as an indexed set of queues.
 *
 */
#include <stdint.h>
#include "hash.h"
#include <stddef.h>
#include <stdlib.h>

/* 
 * SuperFastHash() -- produces a number between 0 and the tablesize-1.
 * 
 * The following (rather complicated) code, has been taken from Paul
 * Hsieh's website under the terms of the BSD license. It's a hash
 * function used all over the place nowadays, including Google Sparse
 * Hash.
 */
#define get16bits(d) (*((const uint16_t *) (d)))

static uint32_t SuperFastHash (const char *data,int len,uint32_t tablesize) {
  uint32_t hash = len, tmp;
  int rem;
  
  if (len <= 0 || data == NULL)
		return 0;
  rem = len & 3;
  len >>= 2;
  /* Main loop */
  for (;len > 0; len--) {
    hash  += get16bits (data);
    tmp    = (get16bits (data+2) << 11) ^ hash;
    hash   = (hash << 16) ^ tmp;
    data  += 2*sizeof (uint16_t);
    hash  += hash >> 11;
  }
  /* Handle end cases */
  switch (rem) {
  case 3: hash += get16bits (data);
    hash ^= hash << 16;
    hash ^= data[sizeof (uint16_t)] << 18;
    hash += hash >> 11;
    break;
  case 2: hash += get16bits (data);
    hash ^= hash << 11;
    hash += hash >> 17;
    break;
  case 1: hash += *data;
    hash ^= hash << 10;
    hash += hash >> 1;
  }
  /* Force "avalanching" of final 127 bits */
  hash ^= hash << 3;
  hash += hash >> 5;
  hash ^= hash << 4;
  hash += hash >> 17;
  hash ^= hash << 25;
  hash += hash >> 6;
  return hash % tablesize;
}

#define TABLE_SIZE 10 

typedef struct hnode {
	char *key;
	int keylen; 
	void *ep;
	struct hnode *next;
} hnode_t_; 

typedef struct hashtable {
	hnode_t_ *data[TABLE_SIZE];
} hashtable_t_; 

hashtable_t *hopen(uint32_t hsize) {
	hashtable_t_ *table = malloc(sizeof(hashtable_t_));
	for (int i = 0; i < TABLE_SIZE; ++i) {
		table->data[i] = NULL; 
	}
	
	return (hashtable_t *) table; 
}

void happly(hashtable_t *htp, void (*fn)(void* ep)) {
	hashtable_t_ *htp_ = (hashtable_t_ *)htp; 
	
	for (int i = 0; i < TABLE_SIZE; ++i) {
		for (hnode_t_ *curr = htp_->data[i]; curr != NULL; curr = curr->next) {
			fn(curr->ep); 
		}
	}

	return; 
}

void *hremove(hashtable_t *htp,
							bool (*searchfn)(void* elementp, const void* searchkeyp),
							const char *key,
							int32_t keylen) {
	hashtable_t_ *htp_ = (hashtable_t_ *) htp;
	
	if (!htp_ || !key || keylen < 0) return NULL;

	uint32_t idx = SuperFastHash(key, keylen, TABLE_SIZE);
	void *result = NULL;
	
	for (hnode_t_ *curr = htp_->data[idx], *prev = NULL; curr != NULL; curr = curr->next) {
		if (curr->keylen == keylen && searchfn(curr->ep, (const void *)key)) {
			if (prev) {
				prev->next = curr->next;
			} else {
				htp_->data[idx] = curr->next;
			}

			result = (void *) curr->ep;

			free(curr); 
			break;
		}
	}

	return result; 
}


