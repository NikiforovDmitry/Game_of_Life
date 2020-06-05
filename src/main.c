#include "curs_library.h"
#include "curs_neighbours.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define _WORLD_WIDTH_ 20
#define _WORLD_HEIGHT_ 20
#define _SIZE_ 10


int main()
{
    struct point world[_WORLD_WIDTH_][_WORLD_HEIGHT_];
    struct point prev_world[_WORLD_WIDTH_][_WORLD_HEIGHT_];
    InitializeWorld(world);
    int live_points = -1, opt, count = 0, i, CycledCount = 0;
    do {
        PrintWorld(world);
        CopyWorld(world, prev_world);
        CopyWorld(world, worlds[CycledCount].w);
        NextGen(world, prev_world);
        opt = CompareWorlds(world, prev_world);
        for (i = 0; i < CycledCount; i++) {
            if (CompareWorlds(world, worlds[i].w) == 1) {
                opt = 1;
                printf("Цикличность\n");
                break;
            }
        }
        live_points = getLiveCount(world);
        printf("Живые клетки - %d\n", live_points);
        if (live_points == 0) {
            printf("Живых клеток не осталось\n");
        }
        if (CycledCount < _SIZE_) {
            CycledCount++;
        } else {
            CycledCount = 0;
        }
        count++;
        sleep(1);
    } while (opt < 0 && live_points != 0);
    if (opt == 1) {
        printf("Достигнуты устойчивые позиции клеток\nКоличество дней %d\n",
               count);
    }
    return 0;
}
