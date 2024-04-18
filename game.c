#include "game.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

Game game_new() {
  Game g = (Game)malloc(sizeof(struct Game));
  g->grid = (int **)malloc(3 * sizeof(int *));
  for (int i = 0; i < 3; i++) {
    g->grid[i] = (int *)malloc(3 * sizeof(int));
    for (int j = 0; j < 3; j++) {
      g->grid[i][j] = 0;
    }
  }
  return g;
}

Game game_goal() {
  Game g = game_new();
  int grid[3][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}};
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      g->grid[i][j] = grid[i][j];
  return g;
}

void game_init(Game g, int values[9]) {
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      g->grid[i][j] = values[i * 3 + j];
}

void game_init_random(Game g) {
  srand(time(NULL));

  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      g->grid[i][j] = 0;

  for (int k = 1; k < 9; k++) {
    int i = rand() % 3;
    int j = rand() % 3;
    while (g->grid[i][j] != k) {
      if (g->grid[i][j] == 0)
        g->grid[i][j] = k;
      else {
        i = rand() % 3;
        j = rand() % 3;
      }
    }
  }
}

void game_copy(Game src, Game dst) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      dst->grid[i][j] = src->grid[i][j];
    }
  }
}

void game_free(Game g) {
  for (int i = 0; i < 3; i++) {
    free(g->grid[i]);
  }
  free(g->grid);
  free(g);
}

int game_is_goal(Game g) {
  int goal[3][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}};
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      if (g->grid[i][j] != goal[i][j])
        return 0;
  return 1;
}

int game_do_action(Game g, int action) {
  int zeroi, zeroj;
  int numi, numj;
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++) {
      if (g->grid[i][j] == 0) {
        zeroi = i;
        zeroj = j;
      }
      if (g->grid[i][j] == action) {
        numi = i;
        numj = j;
      }
    }

  if (numi == zeroi || numj == zeroj) {
    if (numi == zeroi + 1 || numi == zeroi - 1) {
      g->grid[numi][numj] = 0;
      g->grid[zeroi][zeroj] = action;
      return 1;
    }
    if (numj == zeroj + 1 || numj == zeroj - 1) {
      g->grid[numi][numj] = 0;
      g->grid[zeroi][zeroj] = action;
      return 1;
    }
  }
  return 0;
}

int game_hash(Game g) {
  int hash = 0;

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      hash = 10 * hash + g->grid[i][j];
    }
  }

  return hash;
}

void game_print(Game g) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      printf("%d ", g->grid[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

int game_is_solvable(Game g) {
  int inversions = 0;
  int grid[9];
  int k = 0;

  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      grid[k++] = g->grid[i][j];

  for (int i = 0; i < 9; i++) {
    if (grid[i] == 0)
      continue;
    for (int j = i + 1; j < 9; j++) {
      if (grid[j] == 0)
        continue;
      if (grid[i] > grid[j])
        inversions++;
    }
  }

  return inversions % 2 == 0;
}
