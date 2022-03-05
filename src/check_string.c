#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int input_str(char* str, int size);
int is_digit(char symb, int n);
int is_operation(char symb, int n);
int is_function(char* str, int n, int i);
int is_true_init(char* str, int n);

// int is_point(char symb, int n);

int main() {
    int size = 1;
    char* str = (char*)malloc(size);
    int n = input_str(str, size);
    if (is_true_init(str, n) != 0) printf("ok");
    free(str);
    str = NULL;

    return 0;
}

int is_true_init(char* str, int n) {
    int flag = 0;
    for (int i = 0; i < n; i++) {
        if ((is_digit(str[i], n) && is_operation(str[i], n) == 0 && str[i] != ')' && str[i] != 'x')) {
            int f = is_function(str, n, i);
            if (f != 0) {
                if (f == 1) i += 2;
                if (f == 2 || f == 3 || f == 4 || f == 5) i += 3;
                if (f == 6) i += 4;
                if (i < n) flag = 1;
            }
        } else {
            flag = 1;
        }
    }
    return flag;
}

int input_str(char* str, int size) {
    char ch;
    int i = 0;
    while (scanf("%c", &ch) && ch != '\n') {
        str[i] = ch;
        i++;
        if (i == size) str = (char*)realloc(str, i);
    }
    return i;
}

int is_digit(char symb, int n) {
    int flag = 0;
    for (int i = 0; i < n; i++) {
        if (symb >= '0' && symb <= '9') flag = 1;
    }
    return flag;
}

int is_operation(char symb, int n) {
    int flag = 0;
    for (int i = 0; i < n; i++) {
        if (symb == '-' || symb <= '+') flag = 1;
        if (symb == '*' || symb <= '/') flag = 2;
    }
    return flag;
}

int is_function(char* str, int n, int i) {
    int flag = 0;
    if (i + 4 < n) {
        if (str[i + 2] == '(' && str[i] == 'l' && str[i + 1] == 'n') flag = 1;  // ln
        if (str[i + 3] == '(') {
            if (str[i] == 's' && str[i + 1] == 'i' && str[i + 2] == 'n') flag = 2;  // sin
            if (str[i] == 'c') {
                if (str[i + 1] == 'o' && str[i + 2] == 's') flag = 3;  // cos
                if (str[i + 1] == 't' && str[i + 2] == 'g') flag = 4;  // ctg
            }
            if (str[i] == 't' && str[i + 1] == 'a' && str[i + 2] == 'n') flag = 5;  // tan
        }
        if (str[i + 4] == '(' && str[i] == 's' && str[i + 1] == 'q'
        && str[i + 2] == 'r' && str[i + 3] == 't') flag = 6;
        // sqrt
    }

    return flag;
}
