#include <stdio.h>
#include <stdlib.h>
#define LENGTH 101

struct Data {
    int age;
    char* name;
} typedef Data;

void mergesort(int p, int r);
void merge(int p, int q, int r);

Data** vec;

int main() {
    int N;

    scanf("%d", &N);

    vec = (Data**) malloc(N * sizeof(Data*));

    for(int i = 0; i < N; ++i) {
        vec[i] = (Data*) malloc(sizeof(Data));
        vec[i] -> name = (char*) malloc(LENGTH * sizeof(char));
        scanf("%d %s", &(vec[i] -> age), vec[i] -> name);
    }

    mergesort(0, N - 1);

    for(int i = 0; i < N; ++i) {
        printf("%d %s\n", vec[i] -> age, vec[i] -> name);
    }

    for(int i = 0; i < N; ++i) {
        free(vec[i] -> name);
        free(vec[i]);
    }
    free(vec);

    return 0;
}

void mergesort(int p, int r) {
    if(p < r) {
        const int q = (p + r) >> 1;
        mergesort(p, q);
        mergesort(q + 1, r);
        merge(p, q, r);
    }
}

void merge(int p, int q, int r) {
    Data** left = (Data**) malloc((q - p + 1) * sizeof(Data*));
    Data** right = (Data**) malloc((r - q) * sizeof(Data));
    for(int i = p, j = 0; i <= q; ++i, ++j) {
        left[j] = vec[i];
    }
    for(int i = q + 1, j = 0; i <= r; ++i, ++j) {
        right[j] = vec[i];
    }

    int i = 0, j = 0, k = p;
    while(i <= q - p && j <= r - q - 1) {
        if(left[i] -> age <= right[j] -> age) {
            vec[k] = left[i];
            ++i;
        } else {
            vec[k] = right[j];
            ++j;
        }
        ++k;
    }
    while(i <= q - p) {
        vec[k] = left[i];
        ++i, ++k;
    }
    while(j <= r - q - 1) {
        vec[k] = right[j];
        ++j, ++k;
    }
    free(left);
    free(right);
}
