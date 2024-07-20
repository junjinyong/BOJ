#include <stdio.h>

int main(void) {
    char A[4], B[4];
    int compare;
    
    scanf("%s %s", A, B);
    
    if(A[2] != B[2]) {
        compare = (A[2] > B[2]);
    } else if(A[1] != B[1]) {
        compare = (A[1] > B[1]);
    } else {
        compare = (A[0] > B[0]);
    }
    
    if(compare) {
        printf("%c%c%c\n", A[2], A[1], A[0]);
    } else {
        printf("%c%c%c\n", B[2], B[1], B[0]);
    }
    
    return 0;
}
