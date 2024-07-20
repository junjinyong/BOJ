#include <stdio.h>

void swap(int* p, int* q);

int main() {
    int N, M, i, j, arr[100];
    
    scanf("%d %d", &N, &M);
    
    for(int k = 0; k < N; ++k) {
        arr[k] = 1 + k;
    }
    
    while(M--) {
        scanf("%d %d", &i, &j);
        --i;
        --j;
        while(i < j) {
            swap(arr + i, arr + j);
            ++i;
            --j;
        }
    }
    
    for(int k = 0; k < N; ++k) {
        printf("%d ", arr[k]);
    }
    
    return 0;
}

void swap(int* p, int* q) {
    const int temp = *p;
    *p = *q;
    *q = temp;
}
