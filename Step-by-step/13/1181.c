#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 51

char** arr;

void swap(char** p, char** q);
int compare(char* p, char* q);
void quicksort(int p, int r);

int main() {
    int N;
    scanf("%d", &N);

    arr = (char**) malloc(N * sizeof(char*));

    for(int i = 0; i < N; ++i) {
        arr[i] = (char*) malloc(LEN * sizeof(char));
        scanf("%s", arr[i]);
    }

    quicksort(0, N - 1);

    for(int i = 0; i < N; ++i) {
        if(i == 0 || compare(arr[i - 1], arr[i]) != 0) {
            printf("%s\n", arr[i]);
        }
    }

    for(int i = 0; i < N; ++i) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}

void swap(char** p, char** q) {
    char* x = *p;
    *p = *q;
    *q = x;
}

int compare(char* p, char* q) {
    if(strlen(p) == strlen(q)) {
        return strcmp(p, q);
    } else {
        return strlen(p) > strlen(q) ? 1 : -1;
    }
}

void quicksort(int p, int r) {
    if(p < r) {
        char key[51];
        strcpy(key, arr[p + 100003 % (r - p + 1)]);
        int left = p, right = r, i = p;
        while(i <= right) {
            const int num = compare(arr[i], key);
            if(num > 0) {
                swap(arr + i, arr + right);
                --right;
            } else {
                if(num < 0) {
                    swap(arr + i, arr + left);
                    ++left;
                }
                ++i;
            }
        }
        quicksort(p, left - 1);
        quicksort(right + 1, r);
    }
}
