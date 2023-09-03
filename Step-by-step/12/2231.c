#include <stdio.h>

int func(int n);

int main() {
    int N;
    scanf("%d", &N);
    
    for(int i = 1; i <= N; ++i) {
        if(func(i) == N) {
            printf("%d\n", i);
            return 0;
        }
    }
    
    printf("0\n");
    
    return 0;
}

int func(int n) {
    int result = n;
    while(n) {
        result = result + (n % 10);
        n = n / 10;
    }
    return result;
}
