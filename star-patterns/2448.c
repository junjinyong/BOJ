#include <stdio.h>
#include <string.h>
#define MAX 3072

char arr[MAX][MAX + MAX];

void f(int x, int y, int n) {
    if (n == 3) {
        arr[x][y + 2] = '*';
        arr[x + 1][y + 1] = '*';
        arr[x + 1][y + 3] = '*';
        arr[x + 2][y] = '*';
        arr[x + 2][y + 1] = '*';
        arr[x + 2][y + 2] = '*';
        arr[x + 2][y + 3] = '*';
        arr[x + 2][y + 4] = '*';
    } else {
        const int m = n / 2;

        f(x, y + m, m);
        f(x + m, y, m);
        f(x + m, y + n, m);
    }
}

int main() {
    int N;

    scanf("%d", &N);

    memset(arr, ' ', MAX * MAX * 2);

    f(0, 0, N);

    for (int i = 0; i < N; ++i) {
        arr[i][N + N - 1] = '\0';

        printf("%s\n", arr[i]);
    }

    return 0;
}
