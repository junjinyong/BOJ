#include <stdio.h>

int main() {
    int N, M = -1, sum = 0, arr[1000];
    
    scanf("%d", &N);
    
    for(int i = 0; i < N; ++i) {
        scanf("%d", &arr[i]);
    }
    
    for(int i = 0; i < N; ++i) {
        sum = sum + arr[i];
        
        if (arr[i] > M) {
            M = arr[i];
        }
    }
    
    printf("%lf\n", (double) sum / N / M * 100);
    
    return 0;
}
