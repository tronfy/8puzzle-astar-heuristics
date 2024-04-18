#ifndef HASHSET_H
#define HASHSET_H

typedef struct HashNode {
  int key;
  struct HashNode *next;
} HashNode;

typedef struct {
  HashNode **array;
  int size;
  int capacity;
} HashSet;

int hs_hash(int key, int capacity);
HashSet *hs_create(int capacity);
void hs_add(HashSet *set, int key);
int hs_contains(HashSet *set, int key);
void hs_free(HashSet *set);

#endif
