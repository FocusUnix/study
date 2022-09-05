#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_next(char *pattern, int *next, int len) {
    int i = 0, j = -1;
    next[0] = -1;

    while (i < len) {
        if (j == -1 || pattern[i] == pattern[j]) {
            i++;
            j++;
            next[i] = j;
        } else {
            j = next[j];
        }
    }
}

int main(int argc, char **argv) {
    char *pattern = "abcabx";
    int len = strlen(pattern);

    int next[len];

    get_next(pattern, next, len);

    for (int i = 0; i < len; i++) {
        printf("%d\n", next[i]);
    }

    exit(0);
}