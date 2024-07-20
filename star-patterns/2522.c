#include <stdio.h>

void f(int x, int n);

int main(void) {
    int N;

    scanf("%d", &N);

    f(1, N);

    return 0;
}

void f(const int x, const int n) {
    for (int i = 0; i < n; ++i) {
        printf(i + x < n ? " " : "*");
    }
    printf("\n");

    if (x == n) {
        return;
    } else {
        f(x + 1, n);
    }

    for (int i = 0; i < n; ++i) {
        printf(i + x < n ? " " : "*");
    }
    printf("\n");
}
