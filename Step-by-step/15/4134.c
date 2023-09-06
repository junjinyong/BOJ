#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);
    
    while(T--) {
        unsigned int N;
        scanf("%u", &N);
        
        if(N <= 2) {
            printf("2\n");
            continue;
        }
        while(1) {
            int flag = 1;
            for(unsigned int i = 2; i * i <= N; ++i) {
                if(N % i == 0) {
                    flag = 0;
                    break;
                }
            }
            if(flag) {
                printf("%u\n", N);
                break;
            }
            ++N;
        }
    }
    
    return 0;
}
