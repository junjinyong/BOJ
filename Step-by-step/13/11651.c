#include <stdio.h>
#include <stdlib.h>

struct Point {
    int x;
    int y;
} typedef Point;

Point* vec;

void swap(int p, int q);
int compare(int p, int q);
void quicksort(int p, int r);
void randomize(int p, int r);
int partition(int p, int r);

int main() {
    int N;

    scanf("%d", &N);

    vec = (Point*) malloc(N * sizeof(Point));

    for(int i = 0; i < N; ++i) {
        scanf("%d %d", &vec[i].x, &vec[i].y);
    }

    quicksort(0, N - 1);

    for(int i = 0; i < N; ++i) {
        printf("%d %d\n", vec[i].x, vec[i].y);
    }
    
    free(vec);

    return 0;
}

void swap(int p, int q) {
    const int x = vec[p].x, y = vec[p].y;
    vec[p].x = vec[q].x;
    vec[p].y = vec[q].y;
    vec[q].x = x;
    vec[q].y = y;
}

int compare(int p, int q) {
    if(vec[p].y == vec[q].y) {
        return vec[p].x < vec[q].x;
    } else {
        return vec[p].y < vec[q].y;
    }
}

void quicksort(int p, int r) {
    if(p < r) {
        const int q = partition(p, r);
        quicksort(p, q - 1);
        quicksort(q + 1, r);
    }
}

void randomize(int p, int r) {
    const int q = p + rand() % (r - p + 1);
    swap(q, r);
}

int partition(int p, int r) {
    randomize(p, r);
    int i = p;
    for(int j = p; j < r; ++j) {
        if(compare(j, r)) {
            swap(i, j);
            ++i;
        }
    }
    swap(i,  r);
    return i;
}
