#include <stdio.h>

long long int factorial(long long int n);

int main() {
    long long int N;
    scanf("%lld", &N);
    
    printf("%lld\n", factorial(N));
    
    return 0;
}

long long int factorial(long long int n) {
    if(n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}
