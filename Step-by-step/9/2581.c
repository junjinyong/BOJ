#include <stdio.h>
#define MAX 10001

int main() {
    int M, N, min = 2147483647, sum = 0, arr[MAX] = {1, 1, };
    
    scanf("%d %d", &M, &N);
    
    for(int i = 2; i * i < MAX; i++) {
        if(!arr[i]) {
            for(int j = i * i; j < MAX; j = j + i) {
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
    
    if(min == 2147483647) {
        printf("-1\n");
    } else {
        printf("%d\n%d\n", sum, min);
    }
    
    return 0;
}
