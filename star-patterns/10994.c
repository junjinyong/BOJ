#include <stdio.h>

int main(void) {
    int N;

    scanf("%d", &N);

    const int length = (N << 2) - 3;

    for (int i = 0; i < length; ++i) {
        for (int j = 0; j < length; ++j) {
            if ((i > j) == (i + j < length)) {
                printf((j & 1) ? " " : "*");
            } else {
                printf((i & 1) ? " " : "*");
            }
        }

        printf("\n");
    }

    return 0;
}
