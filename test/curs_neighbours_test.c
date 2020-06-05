#include <ctest.h>
#include <curs_library.h>
#include <curs_neighbours.h>

struct point prev_world[_WORLD_WIDTH_][_WORLD_HEIGHT_];
struct point world[_WORLD_WIDTH_][_WORLD_HEIGHT_];

CTEST(curs_neighbours, CoordinateNeighbours)
{
    signed int exp[8][2];
    signed int nb[8][2];
    exp[0][0] = 2;
    exp[0][1] = 6;
    exp[1][0] = 2;
    exp[1][1] = 7;
    exp[2][0] = 2;
    exp[2][1] = 8;
    exp[3][0] = 3;
    exp[3][1] = 6;
    exp[4][0] = 3;
    exp[4][1] = 8;
    exp[5][0] = 4;
    exp[5][1] = 6;
    exp[6][0] = 4;
    exp[6][1] = 7;
    exp[7][0] = 4;
    exp[7][1] = 8;
    CoordinateNeighbours(nb, 3, 7);
    ASSERT_EQUAL(exp[0][0], nb[0][0]);
    ASSERT_EQUAL(exp[0][1], nb[0][1]);
    ASSERT_EQUAL(exp[1][0], nb[1][0]);
    ASSERT_EQUAL(exp[1][1], nb[1][1]);
    ASSERT_EQUAL(exp[2][0], nb[2][0]);
    ASSERT_EQUAL(exp[2][1], nb[2][1]);
    ASSERT_EQUAL(exp[3][0], nb[3][0]);
    ASSERT_EQUAL(exp[3][1], nb[3][1]);
    ASSERT_EQUAL(exp[4][0], nb[4][0]);
    ASSERT_EQUAL(exp[4][1], nb[4][1]);
    ASSERT_EQUAL(exp[5][0], nb[5][0]);
    ASSERT_EQUAL(exp[5][1], nb[5][1]);
    ASSERT_EQUAL(exp[6][0], nb[6][0]);
    ASSERT_EQUAL(exp[6][1], nb[6][1]);
    ASSERT_EQUAL(exp[7][0], nb[7][0]);
    ASSERT_EQUAL(exp[7][1], nb[7][1]);
}

CTEST(curs_neighbours, getLiveCount1)
{
    int i, j, exp, real;
    for (i = 1; i < _WORLD_WIDTH_; i++) {
        for (j = 1; j < _WORLD_HEIGHT_; j++) {
            if ((i <= 10) && (j <= 20)) {
                world[i][j].Cell = 0;
            } else {
                world[i][j].Cell = 1;
            }
        }
    }
    exp = 171;
    real = getLiveCount(world);
    ASSERT_EQUAL(exp, real);
}

CTEST(curs_neighbours, getLiveCount2)
{
    int i, j, exp, real;
    for (i = 1; i < _WORLD_WIDTH_; i++) {
        for (j = 1; j < _WORLD_HEIGHT_; j++) {
            if ((i <= 0) && (j <= 20)) {
                world[i][j].Cell = 0;
            } else {
                world[i][j].Cell = 1;
            }
        }
    }
    exp = 361;
    real = getLiveCount(world);
    ASSERT_EQUAL(exp, real);
}

CTEST(curs_neighbours, getLiveCount3)
{
    int i, j, exp, real;
    for (i = 1; i < _WORLD_WIDTH_; i++) {
        for (j = 1; j < _WORLD_HEIGHT_; j++) {
            if ((i <= 20) && (j <= 20)) {
                world[i][j].Cell = 0;
            } else {
                world[i][j].Cell = 1;
            }
        }
    }
    exp = 0;
    real = getLiveCount(world);
    ASSERT_EQUAL(exp, real);
}

CTEST(curs_neighbours, CountAliveNeighbours)
{
    int i, j, exp, real;
    for (i = 1; i < _WORLD_WIDTH_; i++) {
        for (j = 1; j < _WORLD_HEIGHT_; j++) {
            if ((i <= 10) && (j <= 20)) {
                world[i][j].Cell = 0;
            } else {
                world[i][j].Cell = 1;
            }
        }
    }
    exp = 3;
    real = CountAliveNeighbours(world, 10, 10);
    ASSERT_EQUAL(exp, real);
}

CTEST(curs_neighbours, CountAliveNeighbours2)
{
    int i, j, exp, real;
    for (i = 1; i < _WORLD_WIDTH_; i++) {
        for (j = 1; j < _WORLD_HEIGHT_; j++) {
            if ((i <= 10) && (j <= 20)) {
                world[i][j].Cell = 0;
            } else {
                world[i][j].Cell = 1;
            }
        }
    }
    exp = 8;
    real = CountAliveNeighbours(world, 15, 15);
    ASSERT_EQUAL(exp, real);
}