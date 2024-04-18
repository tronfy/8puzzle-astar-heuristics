all: build run;

build: game.c heuristics.c hashset.c node.c pqueue.c astar.c
	gcc game.c heuristics.c hashset.c node.c pqueue.c astar.c -o astar;

run: build
	./astar;
