#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000008

typedef long long int llint;

int main() {
    int M, N;
    int* arr = (int*) malloc(MAX * sizeof(int));
    memset(arr, 1, MAX * sizeof(int));
    
    scanf("%d %d", &M, &N);
    
    arr[0] = 0;
    arr[1] = 0;
    for(int i = 2; i <= N; ++i) {
        if(arr[i]) {
            for(llint j = (llint) i * i; j <= N; j = j + i) {
                arr[j] = 0;
            }
        }
    }
    
    for(int i = M; i <= N; ++i) {
        if(arr[i]) {
            printf("%d\n", i);
        }
    }
    
    return 0;
}
