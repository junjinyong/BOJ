#include <stdio.h>

int condition(char first, char second, char third);

int main() {
    char str[302];
    int count = 0, cond;
    
    scanf("%s", str);
    
    for(int i = 0; str[i] != '\0'; ++count) {
        cond = condition(str[i], str[i + 1], str[i + 2]);
        i = i + cond;
    }
    
    printf("%d\n", count);
    
    return 0;
}

int condition(char first, char second, char third) {
    if(first == 'c' && second == '=') {
        return 2;
    } else if(first == 'c' && second == '-') {
        return 2;
    } else if(first == 'd' && second == 'z' && third == '=') {
        return 3;
    } else if(first == 'd' && second == '-') {
        return 2;
    } else if(first == 'l' && second == 'j') {
        return 2;
    } else if(first == 'n' && second == 'j') {
        return 2;
    } else if(first == 's' && second == '=') {
        return 2;
    } else if(first == 'z' && second == '=') {
        return 2;
    } else {
        return 1;
    }
}
