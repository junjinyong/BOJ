#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LENGTH 1000001

int main(void) {
    char* str = (char*) malloc(LENGTH * sizeof(char));
    int count = 1;
    
    gets(str);
    
    int length = (int) strlen(str);
    for(int i = 0; i < length; ++i) {
        if(str[i] == ' ') {
            ++count;
        }
    }
    
    if(str[0] == ' ') {
        --count;
    }
    
    if(str[length - 1] == ' ') {
        --count;
    }
    
    printf("%d\n", count);
    
    free(str);
    
    return 0;
}
