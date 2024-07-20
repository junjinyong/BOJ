#include <stdio.h>

int main() {
    int N, temp, min = 2000000, max = -20000000;
    
    scanf("%d", &N);
    
    while(N--) {
        scanf("%d", &temp);
        
        if(temp > max) {
            max = temp;
        }
        
        if(temp < min) {
            min = temp;
        }
    }
    
    printf("%d %d\n", min, max);
    
    return 0;
}
