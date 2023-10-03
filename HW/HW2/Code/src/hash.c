//hash.c

#include "hash.h"


// Function to initialize the hash map
void initHashMap(HashMap* map) {
    for (int i = 0; i < MAX_WORDS; i++) {
        map->nodes[i] = NULL;
    }
}

// Function to insert a word into the hash map
void insertWord(HashMap* map, const char* word, int index) {
    int hash = 0;
    for (const char* c = word; *c != '\0'; c++) {
        hash += *c;
    }
    int key = hash % MAX_WORDS;

    // Create a new node for the word
    HashMapNode* newNode = (HashMapNode*)malloc(sizeof(HashMapNode));
    if (newNode == NULL) {
        perror("Memory allocation failed");
        exit(1);
    }
    newNode->key = strdup(word);
    newNode->index = index;
    newNode->next = NULL; // Initialize the next pointer

    // Check if the bucket is empty
    if (map->nodes[key] == NULL) {
        map->nodes[key] = newNode;
    } else {
        // Handle chaining by adding the new node to the end of the chain
        HashMapNode* current = map->nodes[key];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to find the index of a word in the hash map
int findIndex(const HashMap* map, const char* word) {
    int hash = 0;
    for (const char* c = word; *c != '\0'; c++) {
        hash += *c;
    }
    int key = hash % MAX_WORDS;

    HashMapNode* node = map->nodes[key];
    while (node != NULL) {
        if (strcmp(node->key, word) == 0) {
            return node->index;
        }
        node = node->next;
    }

    return -1; // Word not found
}


void freeHashMap(HashMap* map) {
    for (int i = 0; i < MAX_WORDS; i++) {
        HashMapNode* node = map->nodes[i];
        while (node != NULL) {
            HashMapNode* temp = node;
            node = node->next;
            free(temp->key);
            free(temp);
        }
        map->nodes[i] = NULL;
    }
}

