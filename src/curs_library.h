#ifndef CURS_LIBRARY_H
#define CURS_LIBRARY_H
#define _WORLD_WIDTH_ 20
#define _WORLD_HEIGHT_ 20
#define _SIZE_ 10
struct point {
    unsigned int Cell : 1;
};
struct cycleWorld {
    struct point w[_WORLD_WIDTH_][_WORLD_HEIGHT_];
};
struct point world[_WORLD_WIDTH_][_WORLD_HEIGHT_];
struct cycleWorld worlds[_SIZE_];
unsigned int RandGen(int min, int max);
void InitializeWorld(struct point world[_WORLD_WIDTH_][_WORLD_HEIGHT_]);
void PrintWorld(struct point world[_WORLD_WIDTH_][_WORLD_HEIGHT_]);
void CopyWorld(struct point src[_WORLD_WIDTH_][_WORLD_HEIGHT_],struct point dect[_WORLD_WIDTH_][_WORLD_HEIGHT_]);
int CompareWorlds(struct point world[_WORLD_WIDTH_][_WORLD_HEIGHT_],struct point prev_world[_WORLD_WIDTH_][_WORLD_HEIGHT_]);
void CoordinateNeighbours(signed int nb[][2], unsigned int x, unsigned int y);
unsigned int getLiveCount(struct point world[_WORLD_WIDTH_][_WORLD_HEIGHT_]);
unsigned int CountAliveNeighbours(struct point world[_WORLD_WIDTH_][_WORLD_HEIGHT_],unsigned int x,unsigned int y);
void NextGen(struct point world[_WORLD_WIDTH_][_WORLD_HEIGHT_],struct point prev_world[_WORLD_WIDTH_][_WORLD_HEIGHT_]);
#endif
