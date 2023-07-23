#include <stdio.h>
#define SIZE 500000

void merge(int p, int q, int r);
void merge_sort(int p, int r);

int count = 0, K = 0, arr[SIZE];

int main() {
    int N;
    scanf("%d %d", &N, &K);
    for(int i = 0; i < N; ++i) {
        scanf("%d", &arr[i]);
    }
    merge_sort(0, N - 1);
    if(count < K) {
        printf("-1\n");
    }
    return 0;
}

void merge(int p, int q, int r) {
    int i = p, j = q + 1, t = 0;
    int temp[r - p + 1];
    while(i <= q && j <= r) {
        if(arr[i] <= arr[j]) {
            temp[t++] = arr[i++];
        } else {
            temp[t++] = arr[j++];
        }
    }
    while(i <= q) {
        temp[t++] = arr[i++];
    }
    while(j <= r) {
        temp[t++] = arr[j++];
    }
    for(i = p; i <= r; i++) {
        arr[i] = temp[i - p];
        if(++count == K) {
            printf("%d\n", temp[i - p]);
        }
    }
}

void merge_sort(int p, int r) {
    if(p < r) {
        int q = (p + r) / 2;
        merge_sort(p, q);
        merge_sort(q + 1, r);
        merge(p, q, r);
    }
}
