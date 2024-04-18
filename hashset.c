#include "hashset.h"
#include <stdio.h>
#include <stdlib.h>

int hs_hash(int key, int capacity) { return key % capacity; }

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
        return; // chave já existe
      }
      current = current->next;
    }
    if (current->key == key) {
      return; // chave já existe no fim da lista
    }
    current->next = newNode;
  }
  set->size++;
}

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
