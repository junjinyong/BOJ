#include <stdio.h>

int main() {
    int X, N, a, b;
    
    scanf("%d %d", &X, &N);

    while(N--) {
        scanf("%d %d", &a, &b);
        X = X - a * b;
    }
    
    printf(X ? "No\n" : "Yes\n");
    
    return 0;
}
