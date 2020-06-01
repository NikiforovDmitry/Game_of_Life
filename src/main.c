#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

unsigned int RandGen(int min, int max)
{
    return min + rand() % (max - min);
}

void InitializeWorld(struct point world[_WORLD_WIDTH_][_WORLD_HEIGHT_])
{
    int i, j, r = 0;
    srand(time(NULL));
    for (i = 1; i < _WORLD_WIDTH_; i++) {
        for (j = 1; j < _WORLD_HEIGHT_; j++) {
            r = RandGen(0, 1001);
            if (r % 2 == 0) {
                world[i][j].Cell = 0;
            } else {
                world[i][j].Cell = 1;
            }
        }
    }
}

void PrintWorld(struct point world[_WORLD_WIDTH_][_WORLD_HEIGHT_])
{
    int i, j = 0;
    for (i = 1; i < _WORLD_WIDTH_; i++) {
        printf("\n");
        for (j = 1; j < _WORLD_HEIGHT_; j++) {
            if (world[i][j].Cell == 1) {
                printf(" * ");
            } else {
                printf(" ");
            }
        }
    }
    printf("\n---------------------------------------------\n");
}

void CopyWorld(
        struct point src[_WORLD_WIDTH_][_WORLD_HEIGHT_],
        struct point dect[_WORLD_WIDTH_][_WORLD_HEIGHT_])
{
    unsigned int i, j;
    for (i = 0; i < _WORLD_WIDTH_; i++) {
        for (j = 0; j < _WORLD_HEIGHT_; j++) {
            dect[i][j] = src[i][j];
        }
    }
}

void CoordinateNeighbours(signed int nb[][2], unsigned int x, unsigned int y)
{
    unsigned int i, j, k = 0;
    for (i = x - 1; i <= x + 1; i++) {
        for (j = y - 1; j <= y + 1; j++) {
            if (i == x && j == y) {
                continue;
            }
            nb[k][0] = i;
            nb[k][1] = j;
            k++;
        }
    }
}

int main(int t, char const* n[])
{
    struct point world[_WORLD_WIDTH_][_WORLD_HEIGHT_];
    struct point prev_world[_WORLD_WIDTH_][_WORLD_HEIGHT_];
    InitializeWorld(world);
}
