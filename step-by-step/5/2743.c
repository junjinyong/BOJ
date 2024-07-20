#include <stdio.h>

int main(void) {
    char arr[101];
    int index = 0;
    
    scanf("%s", arr);
    
    while(arr[index] != '\0') {
        ++index;
    }
    
    printf("%d\n", index);
    
    return 0;
}
