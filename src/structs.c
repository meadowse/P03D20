#include <stdlib.h>
#include <stdio.h>
#include "structs.h"

struct Queue_Node *create_node(int id, double rez) {
    struct Queue_Node *que = malloc(sizeof(struct Queue_Node));
    if (que != NULL) {
        que->id = id;
        que->rez = rez;
        que->next = NULL;
    }
    return que;
}

Queue *create_queue() {
    Queue *que = malloc(sizeof(Queue));
    if (que != NULL) {
        que->first = NULL;
    }
    return que;
}

void add_queue(Queue *que, int id, double rez) {
    struct Queue_Node *node = create_node(id, rez);
    if (que->first == NULL) {
        que->first = node;
    } else {
        struct Queue_Node *last_node = que->first;
        while (last_node->next != NULL) {
            last_node = last_node->next;
        }
        last_node->next = node;
    }
}

int take_queue(Queue *que, int *id, double *rez) {
    int flag = 0;
    if (que->first != NULL) {
        *id = que->first->id;
        *rez = que->first->rez;
        struct Queue_Node *next = que->first->next;
        free(que->first);
        que->first = next;
    } else {
        flag = 1;
    }
    return flag;
}

void kill_queue(Queue *que) {
    struct Queue_Node *next = que->first;
    while (next != NULL) {
        struct Queue_Node *n = next->next;
        free(next);
        next = n;
    }
    free(que);
}

Queue *clone_queue(Queue *que) {
    Queue *q = create_queue();
    if (q != NULL) {
        struct Queue_Node *node = que->first;
        while (node != NULL) {
            add_queue(q, node->id, node->rez);
            node = node->next;
        }
    }
    return q;
}

Stack *create_stack() {
    Stack *st = malloc(sizeof(Queue));
    if (st != NULL) {
        st->last = NULL;
    }
    return st;
}

void add_stack(Stack *stack, int id, double rez) {
    struct Queue_Node *node = create_node(id, rez);
    if (node != NULL) {
        node->next = stack->last;
        stack->last = node;
    }
}

int take_stack(Stack *stack, int *id, double *rez) {
    int flag = 0;
    if (stack->last != NULL) {
        *id = stack->last->id;
        *rez = stack->last->rez;
        struct Queue_Node *n = stack->last->next;
        free(stack->last);
        stack->last = n;
    } else {
        flag = 1;
    }
    return flag;
}

void kill_stack(Stack *stack) {
    struct Queue_Node *st = stack->last;
    while (st != NULL) {
        struct Queue_Node *n = st->next;
        free(st);
        st = n;
    }
    free(stack);
}

