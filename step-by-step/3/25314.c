#include <stdio.h>

int main() {
    int N;
    
    scanf("%d", &N);
    
    N = N >> 2;

    while(N--) {
        printf("long ");
    }
    printf("int\n");
    
    return 0;
}
