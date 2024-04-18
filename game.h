#ifndef GAME_H
#define GAME_H

struct Game {
  int **grid;
};

typedef struct Game *Game;

Game game_new();
Game game_goal();
void game_copy(Game src, Game dst);
void game_free(Game g);
void game_print(Game g);
int game_is_goal(Game g);

void game_init(Game g, int values[9]);
void game_init_random(Game g);
int game_do_action(Game g, int action);
int game_hash(Game g);
int game_is_solvable(Game g);

#endif
