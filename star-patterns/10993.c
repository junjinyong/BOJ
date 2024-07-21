#include <stdio.h>

void print(char ch, int n);
inline int power(int n);
void f(int x, int n);

int main(void) {
    int N;

    scanf("%d", &N);

    const int start = N & 1 ? power(N) - 2 : 0;
    const int end = N & 1 ? -1 : power(N) - 1;
    const int increment = N & 1 ? -1 : 1;

    for (int i = start; i != end; i = i + increment) {
        f(i, N);
        printf("\n");
    }

    return 0;
}

void print(const char ch, int n) {
    while(n--) {
        printf("%c", ch);
    }
}

inline int power(const int n) {
    return 1 << n;
}

void f(const int x, const int n) {
    if (x == 0) {
        print('*', power(n + 1) - 3);
    } else if (x < power(n - 1) - 1) {
        print(' ', x);
        printf("*");
        print(' ', power(n - 1) - x - 1);

        f(power(n - 1) - 1 - x, n - 1);

        print(' ', power(n) - x - x - 2);
        printf("*");
    } else if (x == power(n - 1) - 1) {
        print(' ', power(n - 1) - 1);
        print('*', power(n) - 1);
    } else if (x < power(n) - 2) {
        print(' ', x);
        printf("*");
        print(' ', power(n + 1) - 5 - x - x);
        printf("*");
    } else {
        print(' ', x);
        printf("*");
    }
}
