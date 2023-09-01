#include <stdio.h>

void swap(int* p, int* q);
void sort(int* arr);

int main() {
    int arr[3], sum;
    
    scanf("%d %d %d", arr, arr + 1, arr + 2);
    
    sort(arr);
    
    sum = arr[0] + arr[1];
    
    printf("%d\n", sum + (arr[2] >= sum ? sum - 1 : arr[2]));
    
    return 0;
}

void swap(int* p, int* q) {
    const int temp = *p;
    *p = *q;
    *q = temp;
}

void sort(int* arr) {
    if(arr[0] > arr[1]) {
        swap(arr, arr + 1);
    }
    if(arr[1] > arr[2]) {
        swap(arr + 1, arr + 2);
    }
    if(arr[0] > arr[1]) {
        swap(arr, arr + 1);
    }
}
