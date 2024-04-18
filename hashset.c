#include "hashset.h"
#include <stdio.h>
#include <stdlib.h>

// Simple hash function
int hs_hash(int key, int capacity) { return key % capacity; }

// Create a new HashSet
HashSet *hs_create(int capacity) {
  HashSet *set = (HashSet *)malloc(sizeof(HashSet));
  set->array = (int *)malloc(capacity * sizeof(int));
  set->size = 0;
  set->capacity = capacity;
  return set;
}

// Add an integer to the HashSet
void hs_add(HashSet *set, int key) {
  int index = hs_hash(key, set->capacity);
  if (set->array[index] == 0) { // Assuming 0 is not a valid key
    set->array[index] = key;
    set->size++;
  }
}

// Check if an integer is in the HashSet
int hs_contains(HashSet *set, int key) {
  int index = hs_hash(key, set->capacity);
  return set->array[index] == key;
}

// Free the memory allocated for the HashSet
void freeHashSet(HashSet *set) {
  free(set->array);
  free(set);
}
