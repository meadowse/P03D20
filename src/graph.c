#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "graph.h"

#define false 0
#define true 1

int main(void) {
    Grid *g;
    g = Grid_new(25, 80);
    Grid_clear(g);
    for (int x = 0; x < g->w; x++) {
        float j = x * 0.05 * M_PI;
        float i = sin(cos(2 * j));
        i = i * 21 + 3 + (1 - i) * 10;
        int y = round(i);
        if (y >= 0 && y <= 24)
            sustain(g, x, y);}
    Grid_print(g);
    Grid_free(g);
    return 0;
}
/* Координатная плоскость.
 Точки не инициализированы и не определены. */
Grid *Grid_new(int h, int w) {
    Grid *g = malloc(sizeof(Grid));
    if (!g) return NULL;
    g->w = w;
    g->h = h;
    g->cells = malloc(sizeof(Cell) * w * h);
    if (!g->cells) {
        free(g);
        return NULL;
    }
    return g;
}
/* Почистить зарезервированую память. */
void Grid_clear(Grid *g) {
    int x, y;
    for (x = 0; x < g->w; x++) {
        for (y = 0; y < g->h; y++)
            kill(g, x, y);
    }
}
/* Обнулить точки на координатной плоскости. */
void kill(Grid *g, int x, int y) {
    Grid_get_cell(g, x, y)->function = false;
}
/* Точки на координатной плоскости. */
Cell *Grid_get_cell(Grid *g, int x, int y) {
    return &(g->cells[y * g->w + x]);
}
/* Статус точки. */
boolean function(Grid *g, int x, int y) {
    return Grid_get_cell(g, x, y)->function;
}
/* Активация точки графика функции. */
void sustain(Grid *g, int x, int y) {
    Grid_get_cell(g, x, y)->function = true;
}
void Grid_print(Grid *g) { /* Печатает функцию. */
    int x, y;
    for (y = 0; y < g->h; y++) {
        for (x = 0; x < g->w; x++) {
            if (function(g, x, y))
                printf("*");
            else
                printf(".");
        }
        printf("\n");
  }
}
/* Освободить динамическую память. */
void Grid_free(Grid *g) {
    free(g->cells);
    free(g);
}
