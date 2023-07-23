#include <stdio.h>
#define MAX 64

int arr[MAX][MAX];

void func(int p, int q, int r, int s);
int color(int p, int q, int r, int s);

int main() {
    int N;
    scanf("%d", &N);
    
    for(int i = 0; i < N; i++) {
        getchar();
        for(int j = 0; j < N; j++) {
            arr[i][j] = (getchar() == '1');
        }
    }
    
    func(0, 0, N - 1, N - 1);
    
    return 0;
}

void func(int p, int q, int r, int s) {
    const int col = color(p, q, r, s);
    
    if(col > 0) {
        printf("%d", col - 1);
    } else {
        int m1 = (p + r) >> 1, m2 = (q + s) >> 1;
        
        printf("(");
        func(p, q, m1, m2);
        func(p, m2 + 1, m1, s);
        func(m1 + 1, q, r, m2);
        func(m1 + 1, m2 + 1, r, s);
        printf(")");
    }
}

int color(int p, int q, int r, int s) {
    const int col = arr[p][q];
    
    for(int i = p; i <= r; i++) {
        for(int j = q; j <= s; j++) {
            if(col != arr[i][j]) {
                return 0;
            }
        }
    }
    
    return 1 + col;
}
