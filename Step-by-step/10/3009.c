#include <stdio.h>

struct point {
    int x;
    int y;
} typedef point;

int right(point* p1, point* p2, point* p3);
void last(point* target, point* p1, point* p2, point* p3);

int main() {
    point target, p[3];
    
    for(int i = 0; i < 3; ++i) {
        scanf("%d %d", &p[i].x, &p[i].y);
    }
    
    if(right(p, p + 1, p + 2)) {
        last(&target, p, p + 1, p + 2);
    } else if(right(p + 1, p + 2, p)) {
        last(&target, p + 1, p + 2, p);
    } else {
        last(&target, p + 2, p, p + 1);
    }
    
    printf("%d %d\n", target.x, target.y);
    
    return 0;
}

inline int right(point* const p1, point* const p2, point* const p3) {
    return ((p2 -> x) - (p1 -> x)) * ((p3 -> x) - (p1 -> x)) + ((p2 -> y) - (p1 -> y)) * ((p3 -> y) - (p1 -> y)) == 0;
}

inline void last(point* target, point* const p1, point* const p2, point* const p3) {
    target -> x = (p2 -> x) + (p3 -> x) - (p1 -> x);
    target -> y = (p2 -> y) + (p3 -> y) - (p1 -> y);
}
