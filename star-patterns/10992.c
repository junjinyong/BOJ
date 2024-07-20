#include <stdio.h>
#define HEIGHT 100
#define WIDTH 200


int main() {
    int N;
    char arr[100][200] = {0, };

    scanf("%d", &N);

    for(int i = 0; i < N + N - 1; ++i) {
        arr[N - 1][i] = '*';
    }

    for(int i = 0; i < N - 1; ++i) {
        for(int j = 0; j < N - 1 - i; ++j) {
            arr[i][j] = ' ';
        }

        arr[i][N - 1 - i] = '*';

        for(int j = N - i; j < N + i - 1; ++j) {
            arr[i][j] = ' ';
        }

        arr[i][N + i - 1] = '*';
    }

    for(int i = 0; i < N; ++i) {
        printf("%s\n", arr[i]);
    }

    return 0;
}

