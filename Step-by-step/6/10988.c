#include <stdio.h>

int main(void) {
    char arr[101];
    
    scanf("%s", arr);
    
    char* p = arr;
    char* q = arr;
    
    while(*q != '\0') {
        ++q;
    }
    --q;
    
    while(p < q) {
        if(*p != *q) {
            printf("0\n");
            return 0;
        }
        ++p;
        --q;
    }
    
    printf("1\n");
    
    return 0;
}
