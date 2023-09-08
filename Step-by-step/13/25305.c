#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, k;
    
    scanf("%d %d", &N, &k);
    
    int* arr = (int*) malloc(sizeof(int) * N);
    
    for(int i = 0; i < N; ++i) {
        scanf("%d", arr + i);
    }
    
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N - 1; ++j) {
            if(arr[j] > arr[1 + j]) {
                const int temp = arr[j];
                arr[j] = arr[1 + j];
                arr[1 + j] = temp;
            }
        }
    }
    
    printf("%d\n", arr[N - k]);
    
    free(arr);
    
    return 0;
}
