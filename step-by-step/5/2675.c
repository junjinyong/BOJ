#include <stdio.h>

int main(void) {
    int T, R;
    char S[21];
    
    scanf("%d", &T);
    
    while(T--) {
        scanf("%d %s", &R, S);
        
        for(char* p = S; *p != '\0'; ++p) {
            for(int i = 0; i < R; ++i) {
                printf("%c", *p);
            }
        }
        printf("\n");
    }
    
    return 0;
}
