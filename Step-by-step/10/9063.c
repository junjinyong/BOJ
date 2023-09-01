#include <stdio.h>
#define MAX 10000

int main() {
    int N, x_min = MAX, x_max = -MAX, y_min = MAX, y_max = -MAX;
    
    scanf("%d", &N);
    
    while(N--) {
        int x, y;
        
        scanf("%d %d", &x, &y);
    
        if(x < x_min) {
            x_min = x;
        }
        if(x > x_max) {
            x_max = x;
        }
        if(y < y_min) {
            y_min = y;
        }
        if(y > y_max) {
            y_max = y;
        }
    }
    
    printf("%d\n", (x_max - x_min) * (y_max - y_min));
    
    return 0;
}
