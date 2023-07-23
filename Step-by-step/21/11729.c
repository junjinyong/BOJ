#include <stdio.h>

void hanoi(int a, int b, int n);

int main() {
    int N, temp, K = 1;
    scanf("%d", &N);
    temp = N;
    while(temp--) {
        K = K << 1;
    }
    printf("%d\n", --K);
    hanoi(1, 3, N);
    return 0;
}

void hanoi(int a, int b, int n) {
    if(n == 1) {
        printf("%d %d\n", a, b);
    } else {
        int c = 6 - a - b;
        hanoi(a, c, n - 1);
        printf("%d %d\n", a, b);
        hanoi(c, b, n - 1);
    }
}
