#include <stdio.h>

int main() {
    int A, B, C;
    
    scanf("%d %d %d", &A, &B, &C);
    
    A = (A + (B + C) / 60) % 24;
    B = (B + C) % 60;

    printf("%d %d\n", A, B);
    
    return 0;
}
