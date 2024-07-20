#include <stdio.h>

int main() {
    char arr[5][16] = {};
    
    for(int i = 0; i < 5; ++i) {
        scanf("%s", arr[i]);
    }
    
    for(int j = 0; j < 16; ++j) {
        for(int i = 0; i < 5; ++i) {
            if(arr[i][j] != '\n' && arr[i][j] != '\0') {
                printf("%c", arr[i][j]);
            }
        }
    }
    printf("\n");
    
    return 0;
}
