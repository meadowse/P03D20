#include "RPN.h"
#include "structs.h"
#include "defines.h"
#include <stdio.h>
#include <string.h>

Queue *rpn_translation(char *infix_str) {
    int id, i = 0;
    double rez;
    Stack *stack = create_stack();
    Queue *out = create_queue();
    Queue *tokens = token_translation(infix_str);
    while (!take_queue(tokens, &id, &rez)) {
        transformation(id, rez, stack, out, i);
        i++;
    }
    while (!take_stack(stack, &id, &rez)) {
        add_queue(out, id, rez);
    }
    kill_stack(stack);
    kill_queue(tokens);
    return out;
}

Queue *token_translation(char *infix_str) {
    Queue *que = create_queue();
    int is_unary = 1;
    for (int i = 0; infix_str[i] != 0; i++) {
        i = parse_step(infix_str, i, &is_unary, que);
    }
    return que;
}

int priority(int id) {
    int flag = -1;
    if (id == SUM || id == SUB) {
        flag = 1;
    } else if (id == MUL || id == DIV) {
        flag = 2;
    } else if (id == POW) {
        flag = 3;
    }
    return flag;
}

void transformation(int id, double rez, Stack *stack, Queue *out, int i) {
    if (is_digit_or_x(id)) {
        add_queue(out, id, rez);
    } else if (is_prefix(id)) {
        add_stack(stack, id, rez);
    } else if (is_close_bracket(id)) {
        close_bracket(stack, out, i);
    } else if (is_binary(id)) {
        restack_binary(id, stack, out);
        add_stack(stack, id, rez);
    } else {
        printf("RPN is fail. Token %i\n", i);
    }
}

int is_digit_or_x(int id) {
    int flag = 0;
    if (id == NUM || id == X) flag = 1;
    return flag;
}

int is_close_bracket(int id) {
    int flag = 0;
    if (id == CLOSE_BRACKET) flag = 1;
    return flag;
}

int is_prefix(int id) {
    int flag = 0;
    if (id == SIN || id == COS || id == TAN) flag = 1;
    if (id == CTAN || id == SQRT || id == LOGN) flag = 1;
    if (id == UNARY_MINUS || id == OPEN_BRACKET) flag = 1;
    return flag;
}

int is_binary(int id) {
    int flag = 0;
    if (id == MUL || id == DIV || id == SUB) flag = 1;
    if (id == SUM || id == POW) flag = 1;
    return flag;
}

void close_bracket(Stack *stack, Queue *out, int i) {
    int id;
    double rez;
    while (!take_stack(stack, &id, &rez) && id != OPEN_BRACKET) {
        add_queue(out, id, rez);
    }
    if (id != OPEN_BRACKET) {
        printf("no opening bracket at token %d\n", i);
    }
}

void restack_binary(int id, Stack *stack, Queue *out) {
    while (stack->last && priority(stack->last->id) >= priority(id)) {
        int st_id;
        double st_rez;
        take_stack(stack, &st_id, &st_rez);
        add_queue(out, st_id, st_rez);
    }
}

int op_to_int(char id) {
    int flag = -1;
    if (id == 'x') {
        flag = X;
    } else if (id == '+') {
        flag = SUM;
    } else if (id == '-') {
        flag = SUB;
    } else if (id == '/') {
        flag = DIV;
    } else if (id == '*') {
        flag = MUL;
    } else if (id == '^') {
        flag = POW;
    } else if (id == '(') {
        flag = OPEN_BRACKET;
    } else if (id == ')') {
        flag = CLOSE_BRACKET;
    }
    return flag;
}

int trigonometry_to_int(char *str) {
    int flag = -1;
    if (is_sin(str)) {
        flag = SIN;
    } else if (is_cos(str)) {
        flag = COS;
    } else if (is_tan(str)) {
        flag = TAN;
    } else if (is_ctg(str)) {
        flag = CTAN;
    } else if (is_sqrt(str)) {
        flag = SQRT;
    } else if (is_ln(str)) {
        flag = LOGN;
    }
    return flag;
}

int is_sin(char *str) {
    return !strncmp(str, "sin(", trigonometry_length(SIN) + 1);
}

int is_cos(char *str) {
    return !strncmp(str, "cos(", trigonometry_length(COS) + 1);
}

int is_tan(char *str) {
    return !strncmp(str, "tan(", trigonometry_length(TAN) + 1);
}

int is_ctg(char *str) {
    return !strncmp(str, "ctg(", trigonometry_length(CTAN) + 1);
}

int is_sqrt(char *str) {
    return !strncmp(str, "sqrt(", trigonometry_length(SQRT) + 1);
}

int is_ln(char *str) {
    return !strncmp(str, "ln(", trigonometry_length(LOGN) + 1);
}

int trigonometry_length(int id) {
    int flag = 0;
    if (id == TAN || id == LOGN) {
        flag = 2;
    } else if (id == SIN || id == COS || id == CTAN) {
        flag = 3;
    } else if (id == SQRT) {
        flag = 4;
    }
    return flag;
}

int is_digit(char str) {
    return str >= '0' && str <= '9';
}

int digit_length(char *str) {
    int is_point = 0;
    int i = 0;
    while (is_digit(str[i]) || (str[i] == '.' && !is_point)) {
        if (str[i] == '.') is_point = 1;
        i++;
    }
    return i;
}

int parse_step(char *str, int i, int *is_unary, Queue *que) {
    if (is_digit(str[i])) {
        double rez = 0;
        sscanf(str + i, "%lf", &rez);
        i = i + digit_length(str + i) - 1;
        add_queue(que, NUM, rez);
        *is_unary = 0;
    } else if (str[i] == '-' && (*is_unary)) {
        add_queue(que, UNARY_MINUS, 0);
    } else if (op_to_int(str[i]) != -1) {
        add_queue(que, op_to_int(str[i]), 0);
        *is_unary = 1;
    } else if (trigonometry_to_int(str + i) != -1) {
        int id = trigonometry_to_int(str + i);
        add_queue(que, id, 0);
        add_queue(que, OPEN_BRACKET, 0);
        i += trigonometry_length(id);
        *is_unary = 1;
    } else if (str[i] != ' ') {
        printf("parsing is fail at i = %d\n", i);
    }
    return i;
}

