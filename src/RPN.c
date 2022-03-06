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
