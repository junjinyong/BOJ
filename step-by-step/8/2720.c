#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);
    
    while(T--) {
        int C;
        scanf("%d", &C);
        
        const int Q = C / 25;
        C = C % 25;
        const int D = C / 10;
        C = C % 10;
        const int N = C / 5;
        C = C % 5;
        const int P = C;
        
        printf("%d %d %d %d\n", Q, D, N, P);
    }
    
    return 0;
}
