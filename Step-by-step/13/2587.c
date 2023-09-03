#include <stdio.h>

int main() {
    int sum = 0, arr[5];
    
    for(int i = 0; i < 5; ++i) {
        scanf("%d", &arr[i]);
        sum = sum + arr[i];
    }
    
    for(int i = 1; i < 5; ++i) {
        const int temp = arr[i];
        int j = i;
        while(arr[j - 1] > temp) {
            arr[j] = arr[j - 1];
            --j;
        }
        arr[j] = temp;
    }
    
    printf("%d\n%d\n", sum / 5, arr[2]);
    
    return 0;
}
