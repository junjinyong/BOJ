#include <stdio.h>
#define MAX 200

int main(void) {
    int N, M, x, y, z, arr[MAX];
    
    scanf("%d %d", &N, &M);
    
    for(int i = 0; i < MAX; ++i) {
        arr[i] = 0;
    }
    
    for(int i = 0; i < M; ++i) {
        scanf("%d %d %d", &x, &y, &z);
        
        for(int j = x; j <= y; ++j) {
            arr[j] = z;
        }
    }
    
    for(int i = 1; i <= N; ++i) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}
