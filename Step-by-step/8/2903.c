#include <stdio.h>

int main() {
    int N;
    
    scanf("%d", &N);
    
    printf("%d\n", (1 << (N + N)) + (2 << N) + 1);
    
    return 0;
}
