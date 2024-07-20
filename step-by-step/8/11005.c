#include <stdio.h>

int main() {
    int N, B, index = 0;
    char answer[30] = {};
    
    scanf("%d %d", &N, &B);
    
    while(N > 0) {
        const int digit = N % B;
        answer[index] = (char) (digit >= 10 ? digit - 10 + 'A' : digit + '0');
        ++index;
        N = N / B;
    }
    answer[index] = '\0';
    
    for(int i = 0, j = index - 1; i < j; ++i, --j) {
        const signed char temp = answer[i];
        answer[i] = answer[j];
        answer[j] = temp;
    }
    
    printf("%s\n", answer);
    
    return 0;
}
