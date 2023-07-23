#include <stdio.h>
#define MAX 12

int power[MAX] = {1, };

void cantor(int n);

int main() {
    int N;
    for(int i = 1; i < MAX; ++i) {
        power[i] = 3 * power[i - 1];
    }
    while(scanf("%d", &N) != EOF) {
        cantor(N);
        printf("\n");
    }
}

void cantor(int n) {
    if(n == 0) {
        printf("-");
    } else {
        cantor(n - 1);
        for(int i = 0; i < power[n - 1]; ++i) {
            printf(" ");
        }
        cantor(n - 1);
    }
}
