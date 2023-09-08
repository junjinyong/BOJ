#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LENGTH 10000000
#define MAX (LENGTH + LENGTH + 1)

int main() {
    int N, M, *arr = (int*) malloc(MAX * sizeof(int));
    memset(arr, 0, MAX * sizeof(int));
    
    scanf("%d", &N);
    
    while(N--) {
        int x;
        scanf("%d", &x);
        ++arr[x + LENGTH];
    }
    
    scanf("%d", &M);
    while(M--) {
        int x;
        scanf("%d", &x);
        printf("%d ", arr[x + LENGTH]);
    }
    
    free(arr);
    
    return 0;
}
