#include <stdio.h>

int main() {
    int N;
    
    scanf("%d", &N);
    
    while((N & 1) == 0) {
        N = N >> 1;
        printf("2\n");
    }
    
    for(int i = 3; N > 1 && i * i <= N; i = i + 2) {
        while(N % i == 0) {
            N = N / i;
            printf("%d\n", i);
        }
    }
    
    if(N > 1) {
        printf("%d\n", N);
    }
    
    return 0;
}
