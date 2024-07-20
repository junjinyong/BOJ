#include <stdio.h>

int main() {
    unsigned long long int n;
    
    scanf("%llu", &n);
    
    printf("%llu\n3\n", (((n * (n - 1)) >> 1) * (n - 2)) / 3);
    
    return 0;
}
