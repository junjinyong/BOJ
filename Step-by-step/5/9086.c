#include <stdio.h>
#include <string.h>

int main(void) {
    int T;
    char arr[1001];
    
    scanf("%d", &T);
    
    while(T--) {
        scanf("%s", arr);
        
        printf("%c%c\n", arr[0], arr[strlen(arr) - 1]);
    }
    
    return 0;
}
