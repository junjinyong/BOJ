#include <stdio.h>

long long int fibonacci(long long int n);
long long int fibonacci_dp(long long int n);

int fib[21] = {0, 1, };

int main() {
    long long int n;
    scanf("%lld", &n);
    printf("%lld\n", fibonacci(n));
    // printf("%lld\n", fibonacci_dp(n));
    return 0;
}

long long int fibonacci(long long int n) {
    if(n < 2) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}


long long int fibonacci_dp(long long int n) {
    if(n < 2) {
        return n;
    } else if(fib[n] > 0) {
        return fib[n];
    } else {
        return fib[n] = fibonacci(n - 1) + fibonacci(n - 2);
    }
}
