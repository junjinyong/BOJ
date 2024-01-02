#include <stdio.h>

char f(int x, int y, int n) {
    const int m = n / 3;

    if (n == 1) {
        return '*';
    } else if(x < m || x >= 2 * m || y < m || y >= 2 * m) {
        return f(x % m, y % m, m);
    } else {
        return ' ';
    }
}

int main() {
    int N;

    scanf("%d", &N);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            printf("%c", f(i, j, N));
        }
        printf("\n");
    }

    return 0;
}
