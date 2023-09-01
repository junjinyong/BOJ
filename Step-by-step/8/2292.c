#include <stdio.h>

typedef unsigned long long int ullint;

ullint square_root(ullint n);
ullint find(ullint n, ullint p, ullint r);

int main() {
    ullint N;
    
    scanf("%llu", &N);
    
    printf("%llu\n", (square_root(12 * N - 3) + 3 + 5) / 6);
    
    return 0;
}

ullint square_root(ullint n) {
    return find(n, 0, 1000000);
}

ullint find(ullint n, ullint p, ullint r) {
    if(p == r) {
        return p;
    } else {
        ullint q = (p + r) >> 1;
        if(q * q < n) {
            return find(n, q + 1, r);
        } else {
            return find(n, p, q);
        }
    }
}
