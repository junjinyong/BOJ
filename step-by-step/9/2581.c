#include <stdio.h>
#define MAX 2147483647
#define LENGTH 10001

int main() {
    int M, N, min = MAX, sum = 0, arr[LENGTH] = {1, 1, };
    
    scanf("%d %d", &M, &N);
    
    for(int i = 2; i * i < LENGTH; i++) {
        if(!arr[i]) {
            for(int j = i * i; j < LENGTH; j = j + i) {
                arr[j] = 1;
            }
        }
    }
    
    for(int i = M; i <= N; i++) {
        if(!arr[i]) {
            sum = sum + i;
            min = (i < min ? i : min);
        }
    }
    
    if(min == MAX) {
        printf("-1\n");
    } else {
        printf("%d\n%d\n", sum, min);
    }
    
    return 0;
}
