#include <stdio.h>

int maximum(int a, int b, int c);

int main() {
    int A, B, C, prize;
    
    scanf("%d %d %d", &A, &B, &C);
    
    if(A == B && B == C) {
        prize = 10000 + 1000 * A;
    } else if(A == B || B == C) {
        prize = 1000 + 100 * B;
    } else if(C == A) {
        prize = 1000 + 100 * C;
    } else {
        prize = 100 * maximum(A, B, C);
    }
    
    printf("%d\n", prize);
    
    return 0;
}

int maximum(int a, int b, int c) {
    if(a > b) {
        return c > a ? c : a;
    } else {
        return b > c ? b : c;
    }
}
