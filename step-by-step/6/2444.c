#include <stdio.h>

void print_spaces(int n);
void print_stars(int n);

int main() {
    int N;
    
    scanf("%d", &N);
    
    for(int i = 0; i < N; ++i) {
        print_spaces(N - i - 1);
        print_stars(i + i + 1);
        printf("\n");
    }
    
    for(int i = 1; i < N; ++i) {
        print_spaces(i);
        print_stars(((N - i) << 1) - 1);
        printf("\n");
    }
    
    return 0;
}

void print_spaces(int n) {
    while(n--) {
        printf(" ");
    }
}

void print_stars(int n) {
    while(n--) {
        printf("*");
    }
}
