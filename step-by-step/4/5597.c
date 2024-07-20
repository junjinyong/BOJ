#include <stdio.h>

int main() {
    int n, arr[30] = {};
    
    for(int i = 0; i < 28; ++i) {
        scanf("%d", &n);
        arr[n - 1] = 1;
    }
    
    for(int i = 0; i < 30; ++i) {
        if(arr[i] == 0) {
            printf("%d\n", 1 + i);
        }
    }
    
    return 0;
}
