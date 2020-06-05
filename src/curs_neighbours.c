#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

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

unsigned int getLiveCount(struct point world[_WORLD_WIDTH_][_WORLD_HEIGHT_])
{
    int i, j, count = 0;
    for (i = 1; i < _WORLD_WIDTH_; i++) {
        for (j = 1; j < _WORLD_HEIGHT_; j++) {
            if (world[i][j].Cell == 1) {
                count++;
            }
        }
    }
    return count;
}

unsigned int CountAliveNeighbours(
        struct point world[_WORLD_WIDTH_][_WORLD_HEIGHT_],
        unsigned int x,
        unsigned int y)
{
    unsigned int count = 0;
    unsigned int i;
    signed int nb[8][2];
    signed int _x, _y;
    CoordinateNeighbours(nb, x, y);
    for (i = 0; i < 8; i++) {
        _x = nb[i][0];
        _y = nb[i][1];
        if (_x < 0 || _y < 0) {
            continue;
        }
        if (_x >= _WORLD_WIDTH_ || _y >= _WORLD_HEIGHT_) {
            continue;
        }
        if (world[_x][_y].Cell == 1) {
            count++;
        }
    }
    return count;
}

void NextGen(
        struct point world[_WORLD_WIDTH_][_WORLD_HEIGHT_],
        struct point prev_world[_WORLD_WIDTH_][_WORLD_HEIGHT_])
{
    unsigned int i, j;
    unsigned int live_nb;
    struct point p;
    for (i = 0; i < _WORLD_WIDTH_; i++) {
        for (j = 0; j < _WORLD_HEIGHT_; j++) {
            p = prev_world[i][j];
            live_nb = CountAliveNeighbours(prev_world, i, j);
            if (p.Cell == 0) {
                if (live_nb == 3) {
                    world[i][j].Cell = 1;
                }
            } else {
                if (live_nb < 2 || live_nb > 3) {
                    world[i][j].Cell = 0;
                }
            }
        }
    }
}
