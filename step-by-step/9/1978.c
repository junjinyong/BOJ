#include <stdio.h>
#define MAX 1024

int main() {
    int N, count = 0, prime[MAX] = {1, 1, };
    
    for(int i = 2; i <= 32; i++) {
        if(!prime[i]) {
            for(int j = i * i; j < MAX; j = j + i) {
                prime[j] = 1;
            }
        }
    }
    
    scanf("%d", &N);
    
    while(N--) {
        int x;
        scanf("%d", &x);
        
        if(!prime[x]) {
            count++;
        }
    }
    
    printf("%d\n", count);
    
    return 0;
}
