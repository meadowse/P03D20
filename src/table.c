#include "table.h"
#include "calc.h"
#include "defines.h"

void fill_table(Queue *rpn, double table[SRC_W]) {
    for (int i = 0; i < SRC_W; i++) {
        double x = MIN_X + ((MAX_X - MIN_X) / (SRC_W - 1) * i);
        double y = calculate(x, clone_queue(rpn));
        table[i] = y;
    }
    kill_queue(rpn);
}
