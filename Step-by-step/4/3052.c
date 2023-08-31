#include <stdio.h>

int main() {
    int x, count = 0, arr[42] = {};
    
    for(int i = 0; i < 10; ++i) {
        scanf("%d", &x);
        arr[x % 42] = 1;
    }
    
    for(int i = 0; i < 42; ++i) {
        count = count + arr[i];
    }
    
    printf("%d\n", count);
    
    return 0;
}
