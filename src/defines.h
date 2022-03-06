#ifndef SRC_DEFINES_H_
#define SRC_DEFINES_H_

#include <math.h>

/*  Константы связанные с подсчетом и выводом на экран  */
#define MIN_X 0.0
#define MAX_X 4.0 * M_PI
#define MIN_Y -1.0
#define MAX_Y 1.0

#define SRC_W 80
#define SRC_H 25

/*  ID математических операторов / лексем  */
#define NUM 0
#define SUM 1
#define SUB 2
#define MUL 3
#define DIV 4
#define SIN 5
#define COS 6
#define TAN 7
#define CTAN 8
#define SQRT 9
#define LOGN 10
#define X 11
#define POW 12
#define UNARY_MINUS 13

#define OPEN_BRACKET 14
#define CLOSE_BRACKET 15

#endif  // SRC_DEFINES_H_
