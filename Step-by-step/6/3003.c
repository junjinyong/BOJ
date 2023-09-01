#include <stdio.h>

int main(void) {
    int x, arr[6] = {1, 1, 2, 2, 2, 8};
    
    for(int i = 0; i < 6; ++i) {
        scanf("%d", &x);
        printf("%d ", arr[i] - x);
    }
    
    return 0;
}
