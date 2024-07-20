#include <stdio.h>

int minimum(int a, int b, int c, int d);

int main() {
    int x, y, w, h;
    
    scanf("%d %d %d %d", &x, &y, &w, &h);
    
    printf("%d\n", minimum(x, w - x, y, h - y));
    
    return 0;
}

int minimum(int a, int b, int c, int d) {
    const int x = (a < b ? a : b);
    const int y = (c < d ? c : d);
    return x < y ? x : y;
}
