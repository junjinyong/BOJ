inline void swap(int* a, int* b) {
    const int temp = *a;
    *a = *b;
    *b = temp;
}

inline int minimum(int a, int b) {
    return a < b ? a : b;
}

inline int maximum(int a, int b) {
    return a > b ? a : b;
}

int kth(int *a, int n, int k) {
    int start = 0, end = n - 1, key, begin, first, last;
    while(start < end) {
        key = a[start + 1000000007 % (end - start + 1)];
        last = end;
        begin = start;
        for(int i = start; i <= end; ++i) {
            if(a[i] == key) {
                swap(a + i, a + begin);
                ++begin;
            }
        }
        first = begin;
        while(first < last) {
            while(first < last && a[first] < key) {
                ++first;
            }
            while(first < last && a[last] > key) {
                --last;
            }
            swap(a + first, a + last);
        }
        if(a[first] < key) {
            ++first;
        }
        for(int i = start, j = maximum(begin, first + start - begin); j < first; ++i, ++j) {
            a[i] = a[j];
            a[j] = key;
        }
        begin = first + start - begin;
        if(k <= begin) {
            end = maximum(start, begin - 1);
        } else if(k > first) {
            start = minimum(end, first);
        } else {
            return key;
        }
    }
    return a[start];
}
