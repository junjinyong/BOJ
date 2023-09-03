#include <stdio.h>
#define MAX 1000

int main() {
    int N, temp, arr[MAX + MAX + 1] = {};
    
    scanf("%d", &N);
    
    while(N--) {
        scanf("%d", &temp);
        arr[temp + MAX] = 1;
    }
    
    for(int i = 0; i < 2 * MAX + 1; i++) {
        if(arr[i]) {
            printf("%d\n", i - MAX);
        }
    }
    
    return 0;
}
