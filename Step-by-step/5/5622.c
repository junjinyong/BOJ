#include <stdio.h>

int main(void) {
    int lookup[26] = {3, 3, 3,
                      4, 4, 4,
                      5, 5, 5,
                      6, 6, 6,
                      7, 7, 7,
                      8, 8, 8, 8,
                      9, 9, 9,
                      10, 10, 10, 10,
    };
    
    int time = 0;
    char str[16];
    
    scanf("%s", str);
    
    for(int i = 0; str[i] != '\0'; ++i) {
        time = time + lookup[str[i] - 'A'];
    }
    
    printf("%d\n", time);
    
    return 0;
}
