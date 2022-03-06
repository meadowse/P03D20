#ifndef SRC_STRUCTS_H_
#define SRC_STRUCTS_H_

struct Queue_Node {
    struct Queue_Node *next;  // ссылка на след. узел
    int id;  // id лексемы
    double rez;  // значение лексемы, если она хранит число
};

/* 
ф-я создания ноды
Возвращает пустую очередь без нод
*/
struct Queue_Node *create_node(int id, double rez);  // ф-я создания ноды

typedef struct {
    struct Queue_Node *first;  // первый элемент в очереди
} Queue;  // тип очередь

Queue *create_queue();  // ф-я создания очереди

/* 
ф-я вставки лексемы в конец очереди
Queue *que - очередь в конец которой надо вставить лексему
*/
void add_queue(Queue *que, int id, double rez);

/* 
ф-я получения лексемы из начала очереди
Queue *que - очередь из начала которой нужно получить лексему
Возвращает:
1 - если лексема получена успешно
0 - если очередь была пуста
*/
int take_queue(Queue *que, int *id, double *rez);

void kill_queue(Queue *que);  // освобождение памяти очереди

Queue *clone_queue(Queue *que);  // клонирование очереди

typedef struct {
    struct Queue_Node *last;  // первый на выход эл-т стэка
} Stack;  // стэк

/* 
ф-я создания стэка
Возвращает пустой стэк без нод
*/
Stack *create_stack();

/* 
ф-я вставки лексемы в конец стэка
Queue *que - очередь в конец которой надо вставить лексему
*/
void add_stack(Stack *stack, int id, double rez);

/* 
ф-я получения лексемы из конца стэка
Stack *stack - стэк из конца которого нужно получить лексему
Возвращает:
1 - если лексема получена успешно
0 - если стэк был пуст
*/
int take_stack(Stack *stack, int *id, double *rez);

void kill_stack(Stack *stack);  // освобождение памяти стэка

#endif  // SRC_STRUCTS_H_
