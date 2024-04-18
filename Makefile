all: build run;

build: game.c heuristics.c hashset.c node.c pqueue.c astar.c
	gcc -O2 game.c heuristics.c hashset.c node.c pqueue.c astar.c -o astar;

run: build
	./astar;
