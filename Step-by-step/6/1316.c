#include <stdio.h>

int main() {
    int N, count = 0;
    char word[101];
    
    scanf("%d", &N);
    
    while(N--) {
        scanf("%s", word);
    
        int check[26] = {};

        int flag = 1;
        for(int i = 0; word[i] != '\0'; ++i) {
            if(i == 0 || word[i] != word[i - 1]) {
                if(check[word[i] - 'a']) {
                    flag = 0;
                    break;
                } else {
                    check[word[i] - 'a'] = 1;
                }
            }
        }

        count = count + flag;
    }

    printf("%d\n", count);

    return 0;
}
