#include <stdio.h>

#define MAX_N 2000
#define MAX_L 1000

int n;
int ls[MAX_N];
int ms[MAX_L+1];

void sort(int n) {
    for (int i = 0; i < n; i++) {
        ms[ls[i]]++;
    }

    int i = 1;
    int j = 0;
    while (i < MAX_L+1) {
        while (ms[i] > 0) {
            ls[j++] = i;
            ms[i]--;
        }
        i++;
    }
}

/*
 * Return the minimum index whose value is same or larger than the target value if exists, otherwise -1.
 *
 * l: lowest index
 * h: highest index
 * x: target value
 */
int search(int l, int h, int x) {
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

int solve(int n) {
    int count = 0;

    for (int i = n-1; i > 0; i--) {
        for (int j = i-1; j > 0; j--) {
            int a = ls[i];
            int b = ls[j];
            int min_c = a - b + 1;
            int lim_ind = search(0, j-1, min_c);
            // printf("%d %d %d\n", 0, j-1, lim_ind);
            if (lim_ind < 0) {
                break;
            }
            count += j - lim_ind;
        }
    }

    return count;
}

int main(void) {
    scanf("%d\n", &n);

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        ls[i] = x;
    }

    sort(n);

    printf("%d\n", solve(n));

    return 0;
}
