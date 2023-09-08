#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LENGTH 21

char** a;

void swap(char** p, char** q);
int compare(char* p, char* q);
void quicksort(int p, int r);
int search(int p, int r, char* str);

int main() {
    char word[LENGTH];
    int N, M;
    scanf("%d %d", &N, &M);
    
    a = (char**) malloc(N * sizeof(char*));
    char* const temp = (char*) malloc(LENGTH * N * sizeof(char));
    for(int i = 0, j = 0; i < N; ++i, j = j + LENGTH) {
        a[i] = temp + j;
        scanf("%s", a[i]);
    }
    
    quicksort(0, N - 1);
    
    while(M--) {
        scanf("%s", word);
        if(word[0] < 'A') {
            int i = 0, index = 0;
            while(word[i] != '\0') {
                index = 10 * index + word[i] - '0';
                ++i;
            }
            printf("%s\n", temp + LENGTH * (index - 1));
        } else {
            printf("%d\n", (int) (a[search(0, N - 1, word)] - temp) / LENGTH + 1);
        }
    }
    
    free(temp);
    free(a);
    
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
        char key[LENGTH];
        strcpy(key, a[p + 100003 % (r - p + 1)]);
        int left = p, right = r, i = p;
        while(i <= right) {
            const int num = compare(a[i], key);
            if(num > 0) {
                swap(a + i, a + right);
                --right;
            } else {
                if(num < 0) {
                    swap(a + i, a + left);
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
        return strcmp(a[p], str) == 0 ? p : 0;
    } else {
        const int q = (p + r) >> 1;
        const int x = compare(a[q], str);
        if(x > 0) {
            return search(p, q - 1, str);
        } else if(x < 0) {
            return search(q + 1, r, str);
        } else {
            return q;
        }
    }
}
