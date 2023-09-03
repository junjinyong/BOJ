inline void swap(int* a, int* b) {
    const int temp = *a;
    *a = *b;
    *b = temp;
}

int kth(int *a, int n, int k) {
    int *p = a, *r = a + n - 1;
    const int *x = a + k - 1;
    
    while(p < r) {
        const int key = *(p + 1000000007 % (r - p + 1));
        int *left = p, *right = r, *i = p;
        
        while(i <= right) {
            if(*i > key) {
                swap(i, right);
                --right;
            } else {
                if(*i < key) {
                    swap(i, left);
                    ++left;
                }
                ++i;
            }
        }
        
        if(x < left) {
            r = left - 1;
        } else if(x > right) {
            p = right + 1;
        } else {
            return key;
        }
    }
    
    return *p;
}
