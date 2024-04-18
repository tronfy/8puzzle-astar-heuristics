#ifndef HASHSET_H
#define HASHSET_H

typedef struct {
  int *array;
  int size;
  int capacity;
} HashSet;

int hs_hash(int key, int capacity);
HashSet *hs_create(int capacity);
void hs_add(HashSet *set, int key);
int hs_contains(HashSet *set, int key);
void freeHashSet(HashSet *set);

#endif
