#include <stdio.h>

int check(int n);

int main() {
    int N, n = 665;
    
    scanf("%d", &N);
    
    while(N) {
        ++n;
        N = N - check(n);
    }
    
    printf("%d\n", n);
    
    return 0;
}

int check(int n) {
    int count = 0;
    
    while(n > 0) {
        const int next = n / 10;
        
        if(n - 10 * next == 6) {
            ++count;
            if(count == 3) {
                return 1;
            }
        } else {
            count = 0;
        }
        
        n = next;
    }
    
    return 0;
}
