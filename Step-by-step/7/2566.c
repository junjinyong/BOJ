#include <stdio.h>

int main() {
    int max = -1, x, val, arr[10] = {0, }, pos[10] = {0, };
    
    for(int i = 1; i <= 9; ++i) {
        for(int j = 1; j <= 9; ++j) {
            scanf("%d", &val);
            
            if(val > arr[i]) {
                arr[i] = val;
                pos[i] = j;
            }
        }
    }
    
    for(int i = 1; i <= 9; ++i) {
        if(arr[i] > max) {
            max = arr[i];
            x = i;
        }
    }
    
    printf("%d\n%d %d\n", max, x, pos[x] ? pos[x] : 1);
    
    return 0;
}
