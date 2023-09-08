#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 21

void swap(char** p, char** q);
void quicksort(char** arr, int p, int r);

int main() {
    char **a, **b;
    
    int N, M;
    scanf("%d %d", &N, &M);
    
    a = (char**) malloc(N * sizeof(char*));
    b = (char**) malloc(M * sizeof(char*));
    
    char *temp = (char*) malloc((N + M) * LEN * sizeof(char)), *curr = temp;
    for(int i = 0; i < N; ++i, curr = curr + LEN) {
        scanf("%s", a[i] = curr);
    }
    for(int i = 0; i < M; ++i, curr = curr + LEN) {
        scanf("%s", b[i] = curr);
    }
    
    quicksort(a, 0, N - 1);
    quicksort(b, 0, M - 1);
    
    char** c = (char**) malloc((N < M ? N : M) * sizeof(char*));
    int i = 0, j = 0, count = 0;
    while(i < N && j < M) {
        const int ind = strcmp(a[i], b[j]);
        if(ind < 0) {
            ++i;
        } else if(ind > 0) {
            ++j;
        } else {
            c[count] = a[i];
            ++count;
            ++i;
            ++j;
        }
    }
    
    printf("%d\n", count);
    for(int k = 0; k < count; ++k) {
        printf("%s\n", c[k]);
    }
    
    free(temp);
    free(a);
    free(b);
    free(c);
    
    return 0;
}

void swap(char** const p, char** const q) {
    char* const x = *p;
    *p = *q;
    *q = x;
}

void quicksort(char** const arr, int p, int r) {
    if(p < r) {
        char key[LEN];
        strcpy(key, arr[p + 100003 % (r - p + 1)]);
        int left = p, right = r, i = p;
        while(i <= right) {
            const int num = strcmp(arr[i], key);
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
        quicksort(arr, p, left - 1);
        quicksort(arr, right + 1, r);
    }
}
