#include "defines.h"
#include "render.h"
#include <math.h>
#include <stdio.h>

void render(double table[SRC_W]) {
    char screen[SRC_W][SRC_H];
    start_filling(screen);
    for (int i = 0; i < SRC_W; i++) {
        double y = table[i];
        long real_y = lround((y - MIN_Y) / (MAX_Y - MIN_Y) * (SRC_H - 1));
        if (real_y >= 0 && real_y < SRC_H) {
            screen[i][real_y] = '*';
        }
    }
    output(screen);
}

void start_filling(char screen[SRC_W][SRC_H]) {
    for (int j = 0; j < SRC_H ; j++) {
        for (int k = 0; k < SRC_W; k++) {
            screen[k][j] = '.';
        }
    }
}


void output(char screen[SRC_W][SRC_H]) {
    for (int j = 0; j < SRC_H ; j++) {
        printf("\n");
        for (int k = 0; k < SRC_W; k++) {
            printf("%c", screen[k][j]);
        }
    }
}
