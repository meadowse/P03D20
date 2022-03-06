#include "defines.h"
#include "calc.h"
#include "structs.h"
#include <stdlib.h>
#include <stdio.h>

double calculate(double x, Queue *equation) {
    int id, i = 0;
    double rez;
    Stack *stack = create_stack();
    while (!take_queue(equation, &id, &rez)) {
        consume_calc(stack, id, rez, i, x);
        i++;
    }
    take_queue(stack, &id, &rez);
    kill_stack(stack);
    kill_queue(equation);
    return rez;
}

double(*get_unary(int id))(double) {
    double (*flag)(double n) = NULL;
    if (id == UNARY_MINUS) {
        flag = minus;
    } else if (id == COS) {
        flag = cos;
    } else if (id == SIN) {
        flag = sin;
    } else if (id == TAN) {
        flag = tan;
    } else if (id == CTAN) {
        flag = ctg;
    } else if (id == SQRT) {
        flag = sqrt;
    } else if (id == LOGN) {
        flag = log;
    }
    return flag;
}

double(*get_binary(int id))(double, double) {
    double (*flag)(double a, double b) = NULL;
    if (id == SUM) {
        flag = sum;
    } else if (id == SUB) {
        flag = substaction;
    } else if (id == MUL) {
        flag = multiply;
    } else if (id == DIV) {
        flag = division;
    } else if (id == POW) {
        flag = pow;
    }
    return flag;
}

double minus(double numb) {
    return -numb;
}

double sum(double a, double b) {
    return a + b;
}

double dif(double a, double b) {
    return a - b;
}

double mult(double a, double b) {
    return a * b;
}

double div(double a, double b) {
    return a / b;
}

double ctg(double numb) {
    return 1 / tan(numb);
}

void consume_calc(Stack *stack, int id, double rez, int i, double x) {
    if (id == NUM) {
        add_stack(stack, NUM, rez);
    } else if (id == X) {
        add_stack(stack, NUM, x);
    } else if (get_unary(id) != NULL) {
        double (*func)(double num) = get_unary(id);
        take_stack(stack, &id, &rez);
        rez = func(rez);
        add_stack(stack, id, rez);
    } else if (get_binary(id) != NULL) {
        double rez1, rez2;
        double (*func)(double a, double b) = get_binary(id);
        take_stack(stack, &id, &rez1);
        take_stack(stack, &id, &rez2);
        rez1 = func(rez2, rez1);
        add_stack(stack, id, rez1);
    } else {
        printf("calculating token is fail, i = %i\n", i);
    }
}

