#include <stdio.h>

int main() {
    int N, x, y, area = 0, arr[100][100] = {};
    
    scanf("%d", &N);
    
    while(N--) {
        scanf("%d %d", &x, &y);
        
        for(int i = x; i < x + 10 && i < 100; ++i) {
            for(int j = y; j < y + 10 && j < 100; ++j) {
                arr[i][j] = 1;
            }
        }
    }
    
    for(int i = 0; i < 100; ++i) {
        for(int j = 0; j < 100; ++j) {
            area = area + arr[i][j];
        }
    }
    
    printf("%d\n", area);
    
    return 0;
}
