#include <stdio.h>
#include <stdlib.h>

void swap(int* p, int* q);
void quicksort(int* arr, int p, int r);
void randomize(int* arr, int p, int r);
int partition(int* arr, int p, int r);

int main() {
    int A, B;
    int *a, *b;
    
    scanf("%d %d", &A, &B);
    
    a = (int*) malloc(A * sizeof(int));
    b = (int*) malloc(B * sizeof(int));
    for(int i = 0; i < A; ++i) {
        scanf("%d", a + i);
    }
    for(int i = 0; i < B; ++i) {
        scanf("%d", b + i);
    }
    
    quicksort(a, 0, A - 1);
    quicksort(b, 0, B - 1);
    
    int i = 0, j = 0, count = 0;
    while(i < A && j < B) {
        if(a[i] < b[j]) {
            ++count;
            ++i;
        } else if(a[i] > b[j]) {
            ++count;
            ++j;
        } else {
            ++i;
            ++j;
        }
    }
    count = count + A - i + B - j;
    
    printf("%d\n", count);
    
    free(a);
    free(b);
    
    return 0;
}

void swap(int* p, int* q) {
    const int x = *p;
    *p = *q;
    *q = x;
}

void quicksort(int* arr, int p, int r) {
    if(p < r) {
        const int q = partition(arr, p, r);
        quicksort(arr, p, q - 1);
        quicksort(arr, q + 1, r);
    }
}

void randomize(int* arr, int p, int r) {
    const int q = p + rand() % (r - p + 1);
    swap(arr + q, arr + r);
}

int partition(int* arr, int p, int r) {
    randomize(arr, p, r);
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
