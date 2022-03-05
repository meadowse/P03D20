#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define false 0
#define true 1

typedef int boolean;

typedef struct {
    boolean function;
} Cell;

typedef struct {
    int w;
    int h;
    Cell *cells;
} Grid;
/* Области определения и значений.
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
/* Точки в областях определения и значений. */
Cell *Grid_get_cell(Grid *g, int x, int y) {
    x = x;
    y = y;
    return &(g->cells[y * g->w + x]);
}
/* Обнулить точки в областях определения и значений. */
void kill(Grid *g, int x, int y) {
    Grid_get_cell(g, x, y)->function = false;
}
/* Активация точки графика функции. */
void sustain(Grid *g, int x, int y) {
    Grid_get_cell(g, x, y)->function = true;
}
/* Статус точки. */
boolean function(Grid *g, int x, int y) {
    return Grid_get_cell(g, x, y)->function;
}
/* Почистить зарезервированую память. */
void Grid_clear(Grid *g) {
    int x, y;
    for (x = 0; x < g->w; x++) {
        for (y = 0; y < g->h; y++)
            kill(g, x, y);
    }
}
/* Освободить динамическую память. */
void Grid_free(Grid *g) {
    free(g->cells);
    free(g);
}
void Grid_print(Grid *g) { /* печатает функцию */
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
int main(void) {
    Grid *g;
    g = Grid_new(25, 80);
    Grid_clear(g);
    int x, y;
    float i, j;
    for (int x = 0; x < g->w; x++) {
        j = x * 0.05 * M_PI;
        i = sin(cos(2 * j));
        i = i * 21 + 3 + (1 - i) * 10;
        y = round(i);
        if (y >= 0 && y <= 24)
            sustain(g, x, y);}
    Grid_print(g);
    Grid_free(g);
    return 0;
}
