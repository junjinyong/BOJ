#include <stdio.h>

int main() {
    int A, B;
    
    scanf("%d %d", &A, &B);
    
    printf("%.15lf\n", (double) A / B);
    
    return 0;
}
