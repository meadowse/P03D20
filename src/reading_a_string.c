#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int input_string(char* string, int size);

int main() {
    int size = 2;
    char* str = (char*)malloc(size);
    int n = input_string(str, size);
    printf("%d", n);
    free(str);
    str = NULL;

    return 0;
}

int input_string(char* string, int size) {
    char ch;
    int i = 0;
    while (scanf("%c", &ch) && ch != '\n') {
        string[i] = ch;
        i++;
        if (i == size) string = (char*)realloc(string, i);
    }
    return i;
}

