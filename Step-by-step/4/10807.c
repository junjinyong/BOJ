#include <stdio.h>

int main() {
    int N, v, x, arr[201] = {};
    
    scanf("%d", &N);
    
    while(N--) {
        scanf("%d", &x);
        ++arr[100 + x];
    }
    
    scanf("%d", &v);
    
    printf("%d\n", arr[100 + v]);
    
    return 0;
}
