#include <stdio.h>

int main() {
    int N;
    
    scanf("%d", &N);
    
    if(N == 4 || N == 7) {
        printf("-1\n");
    } else {
        const int q = N / 5, r = N - 5 * q;
        const int a = q - r % 3, b = (N - 5 * a) / 3;
        
        printf("%d\n", a + b);
    }
    
    return 0;
}
