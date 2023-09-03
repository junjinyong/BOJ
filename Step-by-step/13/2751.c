#include <stdio.h>
#include <stdlib.h>
#define QuickSort

int arr[1000000];
int temp[1000000];

void swap(int* p, int* q);

void quicksort(int p, int r);
void randomize(int p, int r);
int partition(int p, int r);

void mergesort(int p, int r);
void merge(int p, int q, int r);

int main() {
    int N;
    scanf("%d", &N);
    
    for(int i = 0; i < N; ++i) {
        scanf("%d", arr + i);
    }

#ifdef QuickSort
    quicksort(0, N - 1);
#else
    mergesort(0, N - 1);
#endif
    
    for(int i = 0; i < N; ++i) {
        printf("%d\n", arr[i]);
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


void mergesort(int p, int r) {
    if(p < r) {
        const int q = (p + r) >> 1;
        mergesort(p, q);
        mergesort(q + 1, r);
        merge(p, q, r);
    }
}

void merge(int p, int q, int r) {
    int i = p, j = q + 1, k = 0;
    while(i <= q && j <= r) {
        if(arr[i] < arr[j]) {
            temp[k] = arr[i];
            ++i;
        } else {
            temp[k] = arr[j];
            ++j;
        }
        ++k;
    }
    while(i <= q) {
        temp[k] = arr[i];
        ++i, ++k;
    }
    while(j <= r) {
        temp[k] = arr[j];
        ++j, ++k;
    }
    
    i = p, j = 0;
    while(i <= r) {
        arr[i] = temp[j];
        ++i, ++j;
    }
}
