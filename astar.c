#include "game.h"
#include "hashset.h"
#include "heuristics.h"
#include "node.h"
#include "pqueue.h"

#include <stdio.h>
#include <stdlib.h>

Node aStar(Game start, int (*h)(Game)) {
  PQueue open = pq_new();
  HashSet *closed = hs_create(10000);

  Node startNode = node_new(NULL, 0);
  game_copy(start, startNode->state);
  startNode->g = h(start);
  pq_push(open, startNode);

  while (!pq_empty(open)) {
    Node board = pq_pop(open);
    hs_add(closed, game_hash(board->state));

    if (game_is_goal(board->state)) {
      return board;
    }

    for (int i = 1; i <= 9; i++) {
      Game next = game_new();
      game_copy(board->state, next);
      if (game_do_action(next, i)) {
        Node child = node_new(board, i);
        if (!hs_contains(closed, game_hash(next))) {
          child->g = board->g + 1;
          child->h = h(next);
          pq_push(open, child);
          hs_add(closed, game_hash(next));
        } else {
          node_free(child);
        }
      }
      game_free(next);
    }
  }
}

int main() {
  Game start = game_new();
  // game_init_random(start);

  // game_init(start, (int[]){1, 2, 5, 3, 0, 8, 6, 4, 7}); // 6 passos
  // game_init(start, (int[]){0, 2, 5, 1, 3, 8, 6, 4, 7}); // 8 passos
  // game_init(start, (int[]){0, 4, 2, 1, 8, 5, 3, 7, 6}); // 16 passos
  game_init(start, (int[]){7, 6, 0, 5, 1, 2, 8, 4, 3}); // 26 passos

  game_print(start);

  printf("Resolvendo com heurística: ");

  printf("Distância de Manhattan\n");
  Node solution = aStar(start, h_manhattan);

  // printf("Qtd de peças fora do lugar\n");
  // Node solution = aStar(start, h_misplaced);

  int steps = -1;
  while (solution != NULL) {
    game_print(solution->state);
    solution = solution->parent;
    steps++;
  }
  printf("Resolvido em %d passos\n", steps);
}
