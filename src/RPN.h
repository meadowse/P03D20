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
void transformation(int id, double rez, Stack *stack, Queue *out, int i);

int is_digit_or_x(int id);  // проверка на число/переменную

int is_close_bracket(int id);

int is_prefix(int id);  // унарный минус || cos || sin и тд

int is_binary(int id);

/*
Функция обрабатывающая закрывающую скобку по польской нотации
(выталкивает всё до открывающей скобки из стэка в конечную очередь)
*/
void close_bracket(Stack *stack, Queue *out, int i);

/*
Функция обрабатывающая появление новой бинарной операции.
Выталкивает из стэка в конечную очередь все операции с таким же или большим приоритетом,
если они находятся в голове стэка.
 */
void restack_binary(int id, Stack *stack, Queue *out);

// Функция переводящая операцию из символа ('+', '-' и тд.) в числовой эквивалент
int op_to_int(char id);

// Функция переводящая тригонометрическую ф-ю в числовой эквивалент
int trigonometry_to_int(char *str);

int is_sin(char *str);
int is_cos(char *str);
int is_tan(char *str);
int is_ctg(char *str);
int is_sqrt(char *str);
int is_ln(char *str);

int trigonometry_length(int id);  // длина тригоном-ой ф-ии через id

int digit_length(char *str);  // длина числа

/*
 Функция парсящая одну лексему
str - строка лексем
i - смещение по строке в символах
*is_unary - указатель на переменную, храняющую является ли ближайший минус унарным
*que - указатель на выходную очередь, в которую будут записаны лексемы
Возврат:
i - новое смещение по строке в символах (с утчетом прочтенной лексемы)
*/
int parse_step(char *str, int i, int *is_unary, Queue *que);

#endif  // SRC_RPN_H_
