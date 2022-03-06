#ifndef SRC_GRAPH_H_
#define SRC_GRAPH_H_

typedef int boolean;

typedef struct {
    boolean function;
} Cell;

typedef struct {
    int w;
    int h;
    Cell *cells;
} Grid;

Grid *Grid_new(int h, int w);
Cell *Grid_get_cell(Grid *g, int x, int y);
void kill(Grid *g, int x, int y);
void sustain(Grid *g, int x, int y);
boolean function(Grid *g, int x, int y);
void Grid_clear(Grid *g);
void Grid_free(Grid *g);
void Grid_print(Grid *g);

#endif  // SRC_GRAPH_H_
