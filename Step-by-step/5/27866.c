#include <stdio.h>

int main(void) {
    char arr[1001];
    int i;
    
    scanf("%s %d", arr, &i);
    
    printf("%c\n", arr[i - 1]);
    
    return 0;
}
