#include "heuristics.h"

#include <stdlib.h>

int h_manhattan(Game g) {
  int dist = 0;
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++) {
      int value = g->grid[i][j];
      if (value != 0) {
        int goali = value / 3;
        int goalj = value % 3;
        dist += abs(goali - i) + abs(goalj - j);
      }
    }
  return dist;
}

int h_misplaced(Game g) {
  int dist = 0;
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++) {
      if (g->grid[i][j] != 0 && g->grid[i][j] != i * 3 + j) {
        dist++;
      }
    }
  return dist;
}
