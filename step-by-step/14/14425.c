#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 501

char** arr;

void swap(char** p, char** q);
int compare(char* p, char* q);
void quicksort(int p, int r);
int search(int p, int r, char* str);

int main() {
    char word[LEN];
    int N, M, count = 0;
    scanf("%d %d", &N, &M);
    
    arr = (char**) malloc(N * sizeof(char*));
    
    char *temp = (char*) malloc(N * LEN * sizeof(char)), *curr = temp;
    for(int i = 0; i < N; ++i) {
        arr[i] = curr;
        scanf("%s", arr[i]);
        curr = curr + LEN;
    }
    
    quicksort(0, N - 1);
    
    while(M--) {
        scanf("%s", word);
        count = count + search(0, N - 1, word);
    }
    
    printf("%d\n", count);
    
    return 0;
}

void swap(char** p, char** q) {
    char* const x = *p;
    *p = *q;
    *q = x;
}

int compare(char* p, char* q) {
    if(strlen(p) == strlen(q)) {
        return strcmp(p, q);
    } else {
        return ((strlen(p) > strlen(q)) << 1) - 1;
    }
}

void quicksort(int p, int r) {
    if(p < r) {
        char key[LEN];
        strcpy(key, arr[p + 100003 % (r - p + 1)]);
        int left = p, right = r, i = p;
        while(i <= right) {
            const int num = compare(arr[i], key);
            if(num > 0) {
                swap(arr + i, arr + right);
                --right;
            } else {
                if(num < 0) {
                    swap(arr + i, arr + left);
                    ++left;
                }
                ++i;
            }
        }
        quicksort(p, left - 1);
        quicksort(right + 1, r);
    }
}

int search(int p, int r, char* str) {
    if(p > r) {
        return 0;
    } else if(p == r) {
        return strcmp(arr[p], str) == 0;
    } else {
        const int q = (p + r) >> 1;
        const int x = compare(arr[q], str);
        if(x > 0) {
            return search(p, q - 1, str);
        } else if(x < 0) {
            return search(q + 1, r, str);
        } else {
            return 1;
        }
    }
}
