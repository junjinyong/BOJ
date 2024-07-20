#include <stdio.h>

int main() {
    char N[30];
    int B, answer = 0;
    
    scanf("%s %d", N, &B);
    
    for(int i = 0; N[i] != '\0'; ++i) {
        const int digit = (N[i] > '9' ? N[i] - 'A' + 10 : N[i] - '0');
        answer = B * answer + digit;
    }
    
    printf("%d\n", answer);
    
    return 0;
}
