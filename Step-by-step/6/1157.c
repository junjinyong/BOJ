#include <stdio.h>

int main(void) {
    int count[26] = {};
    char ch;
    
    while((ch = (char) getchar()) != EOF) {
        if(ch >= 'a' && ch <= 'z') {
            ++count[ch - 'a'];
        } else if(ch >= 'A' && ch <= 'Z') {
            ++count[ch - 'A'];
        }
    }
    
    int maximum = -1, number = 0;
    for(int i = 0; i < 26; ++i) {
        if(count[i] > maximum) {
            ch = (char) ('A' + i);
            maximum = count[i];
            number = 1;
        } else if(count[i] == maximum) {
            ++number;
        }
    }
    
    if(number > 1) {
        printf("\?\n");
    } else {
        printf("%c\n", ch);
    }
    
    return 0;
}
