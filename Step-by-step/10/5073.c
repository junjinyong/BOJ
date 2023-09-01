#include <stdio.h>

void swap(int* p, int* q);
void sort(int* arr);

int main() {
    int arr[3];
    
    while(1) {
        scanf("%d %d %d", arr, arr + 1, arr + 2);
        
        sort(arr);
        
        if(arr[2] == 0) {
            break;
        }
        
        if(arr[0] + arr[1] <= arr[2]) {
            printf("Invalid\n");
        } else if(arr[0] == arr[2]) {
            printf("Equilateral\n");
        } else if(arr[0] == arr[1] || arr[1] == arr[2]) {
            printf("Isosceles\n");
        } else {
            printf("Scalene\n");
        }
    }
    
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
