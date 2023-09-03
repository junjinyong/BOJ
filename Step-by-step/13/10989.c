#include <stdio.h>
#define MAX 10000

int main() {
    int N, temp, arr[MAX] = {};
    
    scanf("%d", &N);
    
    while(N--) {
        scanf("%d", &temp);
        ++arr[temp - 1];
    }
    
    for(int i = 1; i <= MAX; i++) {
        int iter = arr[i - 1];
        while(iter--) {
            printf("%d\n", i);
        }
    }
    
    return 0;
}
