#include "hashset.h"
#include <stdio.h>
#include <stdlib.h>

// Simple hash function
int hs_hash(int key, int capacity) { return key % capacity; }

// Create a new HashSet
HashSet *hs_create(int capacity) {
  HashSet *set = (HashSet *)malloc(sizeof(HashSet));
  set->array = (HashNode **)malloc(capacity * sizeof(HashNode *));
  for (int i = 0; i < capacity; i++) {
    set->array[i] = NULL;
  }
  set->size = 0;
  set->capacity = capacity;
  return set;
}

// Add an integer to the HashSet
void hs_add(HashSet *set, int key) {
  int index = hs_hash(key, set->capacity);
  HashNode *newNode = (HashNode *)malloc(sizeof(HashNode));
  newNode->key = key;
  newNode->next = NULL;

  if (set->array[index] == NULL) {
    set->array[index] = newNode;
  } else {
    HashNode *current = set->array[index];
    while (current->next != NULL) {
      if (current->key == key) {
        return; // Key already exists, no need to add
      }
      current = current->next;
    }
    if (current->key == key) {
      return; // Key already exists at the end of the list
    }
    current->next = newNode;
  }
  set->size++;
}

// Check if an integer is in the HashSet
int hs_contains(HashSet *set, int key) {
  int index = hs_hash(key, set->capacity);
  HashNode *current = set->array[index];
  while (current != NULL) {
    if (current->key == key) {
      return 1;
    }
    current = current->next;
  }
  return 0;
}

// Free the memory allocated for the HashSet
void hs_free(HashSet *set) {
  for (int i = 0; i < set->capacity; i++) {
    HashNode *current = set->array[i];
    while (current != NULL) {
      HashNode *next = current->next;
      free(current);
      current = next;
    }
  }
  free(set->array);
  free(set);
}
