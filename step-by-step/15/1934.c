#include <stdio.h>

int gcd(int x, int y);
int lcm(int x, int y);

int main() {
    int T;
    
    scanf("%d", &T);
    
    while(T--) {
        int A, B;
        
        scanf("%d %d", &A, &B);
        
        printf("%d\n", lcm(A, B));
    }
    
    return 0;
}

int gcd(int x, int y) {
    return y == 0 ? x : gcd(y, x % y);
}

inline int lcm(int x, int y) {
    return x * y / gcd(x, y);
}
