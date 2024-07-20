#include <stdio.h>
#define LENGTH 200

int main() {
    while(1) {
        int N, sum = 1, i = 2, index = 0, square, arr[LENGTH] = {};
        
        scanf("%d", &N);
        if(N == -1) {
            break;
        }
        
        while((square = i * i) < N) {
            if(N % i == 0) {
                const int j = N / i;
                arr[index] = i;
                arr[LENGTH - 1 - index] = j;
                sum = sum + i + j;
                ++index;
            }
            ++i;
        }
        
        if(square == N) {
            arr[index] = i;
            sum = sum + i;
        }
        
        if(sum == N) {
            printf("%d = 1", N);
            for(int j = 0; j < LENGTH; ++j) {
                if(arr[j] > 1) {
                    printf(" + %d", arr[j]);
                }
            }
            printf("\n");
        } else {
            printf("%d is NOT perfect. \n", N);
        }
    }
    
    return 0;
}
