#include <stdio.h>
#include <stdlib.h>
#define MAX 246913
#define SQRT_MAX 497

int main() {
    int* arr = (int*) calloc(MAX, sizeof(int));
    int N, count;
    
    arr[0] = 1;
    arr[1] = 1;
    for(int i = 2; i < SQRT_MAX; ++i) {
        if(!arr[i]) {
            for(int j = i * i; j < MAX; j = j + i) {
                arr[j] = 1;
            }
        }
    }
    
    while(1) {
        scanf("%d", &N);
        
        if(N == 0) {
            break;
        } else {
            count = 0;
            
            for(int i = N + 1; i <= N + N; ++i) {
                if(!arr[i]) {
                    ++count;
                }
            }
            
            printf("%d\n", count);
        }
    }
    
    return 0;
}
