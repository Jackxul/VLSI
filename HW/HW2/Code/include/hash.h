//Hash.h
#ifndef _HASH_H_
#define _HASH_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>

#define MAX_WORDS 1500
// Hash map node structure
typedef struct {
    char* key;
    int index;
    struct HashMapNode* next; // Pointer to the next node in the chain
} HashMapNode;

// Hash map structure
typedef struct {
    HashMapNode* nodes[MAX_WORDS];
} HashMap;



void initHashMap(HashMap* map);
void insertWord(HashMap* map, const char* word, int index);
int findIndex(const HashMap* map, const char* word);
void freeHashMap(HashMap* map);




#endif /*HASH_H*/

