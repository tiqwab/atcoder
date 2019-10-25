#include <stdio.h>

#define MAX_N 2000
#define MAX_L 1000

int ls[MAX_N];
/*
 * Return the minimum index whose value is same or larger than the target value if exists, otherwise -1.
 *
 * l: lowest index
 * h: highest index
 * x: target value
 *
 * c.f. binary_search
 */
int lower_bound(int l, int h, int x) {
    if (ls[l] >= x) {
        return l;
    }

    while (h - l > 0) {
        // printf("h: %d, l: %d, mid: %d, v: %d\n", h, l, (l + h) / 2, ls[(l + h / 2)]);

        int mid = (l + h) / 2;
        if (ls[mid] < x) {
            l = mid + 1;
        } else if (ls[mid] > x) {
            h = mid;
        } else {
            h = mid;
        }
    }

    if (ls[l] < x) {
        return -1;
    }

    return l;
}
