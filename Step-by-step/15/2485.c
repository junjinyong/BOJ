#include <stdio.h>

int gcd(int x, int y);

int main() {
    int N, GCD = 0, prev, curr, min, max;
    
    scanf("%d %d", &N, &prev);
    
    min = prev;
    max = prev;
    for(int i = 1; i < N; ++i) {
        scanf("%d", &curr);
        
        GCD = gcd(GCD, curr - prev);
        
        if(curr < min) {
            min = curr;
        }
        if(curr > max) {
            max = curr;
        }
        prev = curr;
    }
    
    printf("%d", (max - min) / GCD + 1 - N);
    
    return 0;
}

int gcd(int x, int y) {
    return y == 0 ? x : gcd(y, x % y);
}
