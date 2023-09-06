#include <stdio.h>

typedef long long int llint;

llint gcd(llint x,llint y);
llint lcm(llint x, llint y);

int main() {
    long long int A, B;
    
    scanf("%lld %lld", &A, &B);
    
    printf("%lld\n", lcm(A, B));
    
    return 0;
}

llint gcd(llint x, llint y) {
    return y == 0 ? x : gcd(y, x % y);
}

inline llint lcm(llint x, llint y) {
    return x * y / gcd(x, y);
}
