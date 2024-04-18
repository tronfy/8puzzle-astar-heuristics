#include "node.h"
#include <stdlib.h>

Node node_new(Node parent, int action) {
  Node child = (Node)malloc(sizeof(struct Node));

  child->state = game_new();
  child->parent = parent;

  if (parent != NULL) {
    game_copy(parent->state, child->state);
    game_do_action(child->state, action);
    child->action = action;
    child->g = parent->g + 1;
  } else {
    child->action = -1;
    child->g = 0;
  }

  return child;
}

void node_free(Node n) {
  game_free(n->state);
  free(n);
}
