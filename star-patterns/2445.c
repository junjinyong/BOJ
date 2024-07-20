#include <stdio.h>

void print_spaces(int num) {
    while(num--) {
        printf(" ");
    }
}

void print_stars(int num) {
    while(num--) {
        printf("*");
    }
}

int main() {
    int N;

    scanf("%d", &N);

    for(int i = 0; i < N; ++i) {
        print_stars(i + 1);
        print_spaces(2 * (N - i - 1));
        print_stars(i + 1);
        printf("\n");
    }

    for(int i = N - 2; i >= 0; --i) {
        print_stars(i + 1);
        print_spaces(2 * (N - i - 1));
        print_stars(i + 1);
        printf("\n");
    }

    return 0;
}
