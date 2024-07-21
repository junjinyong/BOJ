#include <stdio.h>
#include <string.h>

int main() {
    int T;
    char S[1001];

    scanf("%d", &T);

    while(T--) {
        scanf("%s", S);

        const int length = strlen(S);

        char* p = S;
        char* q = S + length - 1;
        while(p < q && *p == *q) {
            ++p;
            --q;
        }

        printf("%d %ld\n", p >= q, 1 + p - S);
    }

    return 0;
}
