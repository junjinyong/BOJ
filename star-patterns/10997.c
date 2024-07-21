#include <stdio.h>
#include <string.h>

int check(int x, int y, int height, int width);

int main(void) {
    int N;

    scanf("%d", &N);

    if (N == 1) {
        printf("*\n");
        return 0;
    }

    const int height = (N << 2) - 1;
    const int width = (N << 2) - 3;
    char arr[400][400];
    memset(arr, ' ', sizeof(arr));

    int x = 0, y = width - 1, dx = 0, dy = -1;
    while(1) {
        arr[x][y] = '*';

        const int x_ = x + dx, y_ = y + dy, x__ = x + dx + dx, y__ = y + dy + dy;
        if (check(x_, y_, height, width) == 0 || check(x__, y__, height, width) && arr[x__][y__] == '*') {
            dx = dx + dy;
            dy = dx - dy;
            dx = dy - dx;

            if (arr[x + dx + dx][y + dy + dy] == '*') {
                break;
            }
        }

        x = x + dx;
        y = y + dy;
    }

    for (int i = 0; i < height; ++i) {
        int length = width - 1;
        while(length >= 0 && arr[i][length] == ' ') {
            --length;
        }
        arr[i][1 + length] = '\0';

        printf("%s\n", arr[i]);
    }

    return 0;
}

inline int check(const int x, const int y, const int height, const int width) {
    return x >= 0 && x < height && y >= 0 && y < width;
}
