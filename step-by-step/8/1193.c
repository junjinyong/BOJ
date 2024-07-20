#include <stdio.h>

int main() {
    int X, i;
    
    scanf("%d", &X);
    
    for(i = 0; X > 0; ++i) {
        X = X - i;
    }
    
    if(i & 1) {
        printf("%d/%d\n", X + i - 1, 1 - X);
    } else {
        printf("%d/%d\n", 1 - X, X + i - 1);
    }
    
    return 0;
}
