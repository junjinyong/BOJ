#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);
    
    while(T--) {
        int C;
        scanf("%d", &C);
        
        int Q = C / 25;
        C = C % 25;
        int D = C / 10;
        C = C % 10;
        int N = C / 5;
        C = C % 5;
        int P = C;
        
        printf("%d %d %d %d\n", Q, D, N, P);
    }
    
    return 0;
}
