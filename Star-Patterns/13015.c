#include <stdio.h>

void print_stars(int n);
void print_spaces(int n);

int main() {
    int N;
    scanf("%d", &N);
    
    print_stars(N);
    print_spaces(N + N - 3);
    print_stars(N);
    printf("\n");
    
    for(int i = 1; i < N - 1; ++i) {
        print_spaces(i);
        printf("*");
        print_spaces(N - 2);
        printf("*");
        print_spaces(((N - i) << 1) - 3);
        printf("*");
        print_spaces(N - 2);
        printf("*\n");
    }
    
    print_spaces(N - 1);
    printf("*");
    print_spaces(N - 2);
    printf("*");
    print_spaces(N - 2);
    printf("*");
    printf("\n");
    
    for(int i = N, x; i < N + N - 2; ++i) {
        x = N + N - 2 - i;
        print_spaces(x);
        printf("*");
        print_spaces(N - 2);
        printf("*");
        print_spaces(((N - x) << 1) - 3);
        printf("*");
        print_spaces(N - 2);
        printf("*\n");
    }
    
    print_stars(N);
    print_spaces(N + N - 3);
    print_stars(N);
    printf("\n");
    
    return 0;
}

void print_stars(int n) {
    for(int i = 0; i < n; ++i) {
        printf("*");
    }
}

void print_spaces(int n) {
    for(int i = 0; i < n; ++i) {
        printf(" ");
    }
}
