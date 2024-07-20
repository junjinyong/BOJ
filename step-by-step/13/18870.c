#include <stdio.h>
#include <stdlib.h>

int *X, *arr;

void swap(int* p, int* q);
void quicksort(int p, int r);
int search(int p, int r, int key);

int main() {
    int N, len = 0;
    scanf("%d", &N);

    X = (int*) malloc(N * sizeof(int));
    arr = (int*) malloc(N * sizeof(int));

    for(int i = 0; i < N; ++i) {
        scanf("%d", X + i);
        arr[i] = X[i];
    }

    quicksort(0, N - 1);

    for(int i = 0; i < N; ++i) {
        if(i == 0 || arr[i - 1] != arr[i]) {
            arr[len] = arr[i];
            ++len;
        }
    }

    for(int i = 0; i < N; ++i) {
        printf("%d ", search(0, len - 1, X[i]));
    }

    free(X);
    free(arr);

    return 0;
}

void swap(int* p, int* q) {
    const int x = *p;
    *p = *q;
    *q = x;
}

void quicksort(int p, int r) {
    if(p < r) {
        const int key = arr[p + 1000000007 % (r - p + 1)];
        int left = p, right = r, i = p;
        while(i <= right) {
            if(arr[i] > key) {
                swap(arr + i, arr + right);
                --right;
            } else {
                if(arr[i] < key) {
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

int search(int p, int r, int key) {
    if(p == r) {
        return p;
    } else {
        const int q = (p + r + 1) >> 1;
        if(arr[q] > key) {
            return search(p, q - 1, key);
        } else {
            return search(q, r, key);
        }
    }
}
