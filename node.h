#include "game.h"

#ifndef NODE_H
#define NODE_H

struct Node {
  Game state;
  int action;
  int g;
  int h;
  struct Node *parent;
};
typedef struct Node *Node;

Node node_new(Node parent, int action);
void node_free(Node n);

#endif
