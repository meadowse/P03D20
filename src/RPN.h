#ifndef SRC_RPN_H_
#define SRC_RPN_H_

#include "structs.h"

/*
ф-я перевода инфиксной строки (char *infix_str) 
в обр. польскую нотацию (алгоритм Дейкстры)
возвращает очередь операций
*/
Queue *rpn_translation(char *infix_str);

/*
ф-я разбиения инфиксной строки (char *infix_str) 
на лексемы
возвращает очередь из лексем в том же порядке, что и в введенной строке
*/
Queue *token_translation(char *infix_str);

int priority(int id);  // возвращает приотритет операции

/*
ф-я преобразования одной операции в rpn (алгоритм Дейкстры)
параметры:
стэк для временного хранения операций
выходная очередь
номер итерации
*/
void transformation(int id, double rez, Stack *stack, Queue *que, int i);

int is_digit(int id);  // проверка на число/переменную

int is_close_bracket(int id);

int is_prefix(int id);  // унарный минус || cos || sin и тд

int is_binary(int id);

/*
Функция обрабатывающая закрывающую скобку по польской нотации
(выталкивает всё до открывающей скобки из стэка в конечную очередь)
*/
void close_bracket(Stack *stack, Queue *que, int i);

/*
Функция обрабатывающая появление новой бинарной операции.
Выталкивает из стэка в конечную очередь все операции с таким же или большим приоритетом,
если они находятся в голове стэка.
 */
void restack_binary(int id, Stack *stack, Queue *que);

// Функция переводящая операцию из символа ('+', '-' и тд.) в числовой эквивалент
int op_to_int(char id);

#endif  // SRC_RPN_H_
