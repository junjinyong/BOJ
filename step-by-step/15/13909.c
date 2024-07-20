#include <stdio.h>
#define SQRT_MAX 45825

int find(int x);
int search(int x, int p, int r);

int main() {
    int N;
    scanf("%d", &N);
    
    printf("%d\n", find(N));
    
    return 0;
}

int find(int x) {
    return search(x, 0, SQRT_MAX);
}

int search(int x, int p, int r) {
    if(p == r) {
        return p;
    } else {
        const int q = (p + r + 1) >> 1;
        return q * q > x ? search(x, p, q - 1) : search(x, q, r);
    }
}
