#include <stdio.h>

int gcd(int x, int y);

int main() {
    int A, B, C, D, G, X, Y;
    
    scanf("%d %d %d %d", &A, &B, &C, &D);
    
    X = A * D + B * C;
    Y = B * D;
    G = gcd(X, Y);
    
    printf("%d %d\n", X / G, Y / G);
    
    return 0;
}

int gcd(int x, int y) {
    return y == 0 ? x : gcd(y, x % y);
}
