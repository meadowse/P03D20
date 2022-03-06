#ifndef SRC_RENDER_H_
#define SRC_RENDER_H_

#include "defines.h"

/*
Ф-я отрисовки графика на экран
table[SRC_W] - массив с y координатами каждой точки на экране
*/
void render(double table[SRC_W]);

/*
заполнение графика '.'
char screen[SRC_W][SRC_H] -  двумерный массив
*/
void start_filling(char screen[SRC_W][SRC_H]);

/*
Ф-я вывода массива с графиком функции в терминал.
*/
void output(char screen[SRC_W][SRC_H]);

#endif  // SRC_RENDER_H_
