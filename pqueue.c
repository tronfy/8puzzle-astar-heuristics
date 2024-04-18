#include "pqueue.h"

#include <stdio.h>
#include <stdlib.h>

PQueue pq_new() {
  PQueue pq = (PQueue)malloc(sizeof(struct PQueue));
  pq->nodes = (Node *)malloc(100 * sizeof(Node));
  pq->size = 0;
  pq->capacity = 100;
  return pq;
}

void pq_push(PQueue pq, Node n) {
  if (pq->size == pq->capacity) {
    pq->capacity *= 2;
    pq->nodes = (Node *)realloc(pq->nodes, pq->capacity * sizeof(Node));
  }
  pq->nodes[pq->size] = n;
  _bubbleUp(pq, pq->size);
  pq->size++;
}

Node pq_pop(PQueue pq) {
  Node n = pq->nodes[0];
  pq->nodes[0] = pq->nodes[pq->size - 1];
  pq->size--;
  _bubbleDown(pq, 0);
  return n;
}

int pq_empty(PQueue pq) { return pq->size == 0; }

void _swap(Node *a, Node *b) {
  Node temp = *a;
  *a = *b;
  *b = temp;
}

void _bubbleUp(PQueue pq, int index) {
  if (index == 0)
    return;
  int parent = (index - 1) / 2;
  if (pq->nodes[index]->g + pq->nodes[index]->h <
      pq->nodes[parent]->g + pq->nodes[parent]->h) {
    _swap(&pq->nodes[index], &pq->nodes[parent]);
    _bubbleUp(pq, parent);
  }
}

void _bubbleDown(PQueue pq, int index) {
  int left = 2 * index + 1;
  int right = 2 * index + 2;
  int smallest = index;
  if (left < pq->size && pq->nodes[left]->g + pq->nodes[left]->h <
                             pq->nodes[smallest]->g + pq->nodes[smallest]->h) {
    smallest = left;
  }
  if (right < pq->size && pq->nodes[right]->g + pq->nodes[right]->h <
                              pq->nodes[smallest]->g + pq->nodes[smallest]->h) {
    smallest = right;
  }
  if (smallest != index) {
    _swap(&pq->nodes[index], &pq->nodes[smallest]);
    _bubbleDown(pq, smallest);
  }
}
