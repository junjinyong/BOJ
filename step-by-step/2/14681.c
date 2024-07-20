#include <stdio.h>

int main(void) {
    int x, y, result;
    
    scanf("%d %d", &x, &y);
    
    if(x < 0) {
        if(y < 0) {
            result = 3;
        } else {
            result = 2;
        }
    } else {
        if(y < 0) {
            result = 4;
        } else {
            result = 1;
        }
    }
    
    printf("%d\n", result);
    
    return 0;
}
