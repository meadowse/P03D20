#include <stdio.h>
#include <stdlib.h>

#include "render.h"
#include "structs.h"
#include "calc.h"
#include "RPN.h"
#include "table.h"
#include "defines.h"

char *safe_gets();

int main() {
    char *test = safe_gets();
    Queue *q = rpn_translation(test);
    double table[SRC_W];
    fill_table(q, table);
    render(table);
    free(test);
}

/**************************************************************************************************
 *  Функция безопастного получения строки. Читает символы до '\n' или до EOF.
 *
 *          Возвращает:
 *  char *string - полученная строка
***************************************************************************************************/
char *safe_gets() {
    char *string = malloc(sizeof(char));
    int c = getchar();
    int i = 0;
    while (c != EOF && c != '\n') {
        char *new = realloc(string, sizeof(char) * (i + 2));
        if (new == NULL) {
            free(string);
        } else {
            string[i] = c;
            c = getchar();
            i++;
        }
    }
    string[i] = 0;
    return string;
}
