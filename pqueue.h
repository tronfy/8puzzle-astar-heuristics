#include "node.h"

#ifndef PQUEUE_H
#define PQUEUE_H

struct PQueue {
  Node *nodes;
  int size;
  int capacity;
};

typedef struct PQueue *PQueue;

PQueue pq_new();
void pq_push(PQueue pq, Node n);
Node pq_pop(PQueue pq);
int pq_empty(PQueue pq);

void _swap(Node *a, Node *b);
void _bubbleUp(PQueue pq, int index);
void _bubbleDown(PQueue pq, int index);

#endif
