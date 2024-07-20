#include <stdio.h>

int main() {
    int arr[10] = {};
    char ch;
    
    while((ch = getchar()) != '\n') {
        ++arr[ch - '0'];
    }
    
    for(int i = 9; i >= 0; i--) {
        while(arr[i]--) {
            printf("%d", i);
        }
    }
    printf("\n");
    
    return 0;
}
