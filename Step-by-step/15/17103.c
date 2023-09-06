#include <stdio.h>
#include <stdlib.h>
#define MAX 1000001
#define NUM 1001

int main() {
    int* prime = (int*) calloc(MAX, sizeof(int));
    prime[0] = 1;
    prime[1] = 1;
    
    for(int i = 2; i < MAX; ++i) {
        if(prime[i] == 0 && i < NUM) {
            for(int j = i * i; j < MAX; j = j + i) {
                prime[j] = 1;
            }
        }
    }
    
    int T;
    scanf("%d", &T);
    
    while(T--) {
        int N;
        scanf("%d", &N);
        
        int count = 2 - prime[N - 2] - prime[N - 3];
        
        for(int i = 5; i + i <= N; i = i + 6) {
            if((prime[i] | prime[N - i]) == 0) {
                ++count;
            }
        }
        
        for(int i = 7; i + i <= N; i = i + 6) {
            if((prime[i] | prime[N - i]) == 0) {
                ++count;
            }
        }
        
        printf("%d\n", count);
    }
    
    return 0;
}
