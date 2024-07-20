#include <stdio.h>

int main() {
    int N, X, val;
    
    scanf("%d %d", &N, &X);
    
    while(N--) {
        scanf("%d", &val);
        if(val < X) {
            printf("%d ", val);
        }
    }
    
    return 0;
}
