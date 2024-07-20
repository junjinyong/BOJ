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

    char *temp = (char*) malloc(N * LEN * sizeof(char)), *curr = temp;
    for(int i = 0; i < N; ++i) {
        arr[i] = curr;
        scanf("%s", arr[i]);
        curr = curr + LEN;
    }

    quicksort(0, N - 1);

    for(int i = 0; i < N; ++i) {
        if(i == 0 || compare(arr[i - 1], arr[i]) != 0) {
            printf("%s\n", arr[i]);
        }
    }

    free(temp);
    free(arr);

    return 0;
}

void swap(char** p, char** q) {
    char* const x = *p;
    *p = *q;
    *q = x;
}

int compare(char* p, char* q) {
    if(strlen(p) == strlen(q)) {
        return strcmp(p, q);
    } else {
        return ((strlen(p) > strlen(q)) << 1) - 1;
    }
}

void quicksort(int p, int r) {
    if(p < r) {
        char key[LEN];
        strcpy(key, arr[p + 100003 % (r - p + 1)]);
        int left = p, right = r;
        for(int i = left; i <= right; ++i) {
            if(compare(arr[i], key) < 0) {
                swap(arr + i, arr + left);
                ++left;
            }
        }
        for(int i = right; i >= left; --i) {
            if(compare(arr[i], key) > 0) {
                swap(arr + i, arr + right);
                --right;
            }
        }
        quicksort(p, left - 1);
        quicksort(right + 1, r);
    }
}
