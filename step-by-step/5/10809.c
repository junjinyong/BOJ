#include <stdio.h>

int main(void) {
    char S[101];
    
    scanf("%s", S);
    
    for(char ch = 'a'; ch <= 'z'; ++ch) {
        int index = 0;
        while(S[index] != ch && S[index] != '\0') {
            ++index;
        }
        if(S[index] == '\0') {
            printf("-1 ");
        } else {
            printf("%d ", index);
        }
    }
    
    return 0;
}
