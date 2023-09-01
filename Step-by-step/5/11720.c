#include <stdio.h>

int main(void) {
    int N, sum = 0;
    
    scanf("%d\n", &N);
    
    while(N--) {
        sum = sum + (getchar() - '0');
    }
    
    printf("%d\n", sum);
    
    return 0;
}
