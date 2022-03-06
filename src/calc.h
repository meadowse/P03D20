#ifndef SRC_CALC_H_
#define SRC_CALC_H_

#include "structs.h"

// подсчет значения у в точке х
double calculate(double x, Queue *equation);

/* 
получениe указателя на функцию обрабатывающую унарный оператор
Возвращает:
double (*flag)(double n) - функция которая обрабатывает этот унарный оператор или
NULL если унарная функция для этого оператора не найдена
*/
double(*get_unary(int id))(double);

/* 
получениe указателя на функцию обрабатывающую бинарный оператор
Возвращает:
double (*flag)(double a, double b) - функция, которая обрабатывает этот бинарный оператор или
NULL если бинарная функция для этого оператора не найдена
*/
double(*get_binary(int id))(double, double);

double minus(double numb);  // унарный минус

double sum(double a, double b);  // '+'
double dif(double a, double b);  // '-'
double mult(double a, double b);  // '*'
double division(double a, double b);  // '/'
double ctg(double numb);

/*
Ф-я потребления калькулятором одной лексемы из выражения, записанного в польской
нотации. Результат вычисления будет помещен в стэк.
Параметры:
*stack - стэк калькулятора для подсчета результата
*/
void consume_calc(Stack *stack, int op, double rez, int i, double x);

#endif  // SRC_CALC_H_
