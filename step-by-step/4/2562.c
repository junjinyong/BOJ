#include <stdio.h>

int main() {
    int x, index = -1, maximum = 0;
    
    for(int i = 0; i < 9; ++i) {
        scanf("%d", &x);
        if(x > maximum) {
            index = i;
            maximum = x;
        }
    }
    
    printf("%d\n%d\n", maximum, 1 + index);
    
    return 0;
}
