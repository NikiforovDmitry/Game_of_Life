#ifndef CURS_NEIGHBOURS_H
#define CURS_NEIGHBOURS_H
#define _WORLD_WIDTH_ 20
#define _WORLD_HEIGHT_ 20
#define _SIZE_ 10
void CoordinateNeighbours(signed int nb[][2], unsigned int x, unsigned int y);
unsigned int getLiveCount(struct point world[_WORLD_WIDTH_][_WORLD_HEIGHT_]);
unsigned int CountAliveNeighbours(
        struct point world[_WORLD_WIDTH_][_WORLD_HEIGHT_],
        unsigned int x,
        unsigned int y);
void NextGen(
        struct point world[_WORLD_WIDTH_][_WORLD_HEIGHT_],
        struct point prev_world[_WORLD_WIDTH_][_WORLD_HEIGHT_]);
#endif