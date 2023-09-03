#include <stdio.h>
#define MAX 50

int main() {
    int N, M, min = 64, arr[MAX][MAX];
    
    scanf("%d %d\n", &N, &M);
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            arr[i][j] = (getchar() == 'B');
        }
        getchar();
    }
    
    for(int i = 0; i <= N - 8; i++) {
        for(int j = 0; j <= M - 8; j++) {
            int sum = 0;
            
            for(int k = 0; k < 8; k++) {
                for(int l = 0; l < 8; l++) {
                    if(arr[i + k][j + l] == ((k + l) & 1)) {
                        ++sum;
                    }
                }
            }
            
            if(sum > 32) {
                sum = 64 - sum;
            }
            if(sum < min) {
                min = sum;
            }
        }
    }
    
    printf("%d\n", min);
    
    return 0;
}
