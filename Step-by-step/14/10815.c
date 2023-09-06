#include <stdio.h>
#include <stdlib.h>

int *arr;

void swap(int* p, int* q);
void quicksort(int p, int r);
void randomize(int p, int r);
int partition(int p, int r);
int search(int p, int r, int x);

int main() {
    int N, M, x;
    
    scanf("%d", &N);
    
    arr = (int*) malloc(N * sizeof(int));
    for(int i = 0; i < N; ++i) {
        scanf("%d", arr + i);
    }
    
    quicksort(0, N - 1);
    
    scanf("%d", &M);
    
    while(M--) {
        scanf("%d", &x);
        
        printf("%d ", search(0, N - 1, x));
    }
    
    return 0;
}

void swap(int* p, int* q) {
    const int x = *p;
    *p = *q;
    *q = x;
}

void quicksort(int p, int r) {
    if(p < r) {
        const int q = partition(p, r);
        quicksort(p, q - 1);
        quicksort(q + 1, r);
    }
}

void randomize(int p, int r) {
    const int q = p + rand() % (r - p + 1);
    swap(arr + q, arr + r);
}

int partition(int p, int r) {
    randomize(p, r);
    const int key = arr[r];
    int i = p;
    for(int j = p; j < r; ++j) {
        if(arr[j] <= key) {
            swap(arr + i, arr + j);
            ++i;
        }
    }
    swap(arr + i, arr + r);
    return i;
}

int search(int p, int r, int x) {
    if(p > r) {
        return 0;
    } else if(p == r) {
        return arr[p] == x;
    } else {
        const int q = (p + r) >> 1;
        if(arr[q] > x) {
            return search(p, q - 1, x);
        } else if(arr[q] < x) {
            return search(q + 1, r, x);
        } else {
            return 1;
        }
    }
}
