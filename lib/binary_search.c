#include <stdbool.h>
#include <stdio.h>

// ref. http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_4_B

bool binary_search(int xs[], int len, int target) {
    int l = 0, h = len-1, mid;

    while (h >= l) {
        mid = (l + h) / 2;
        if (xs[mid] < target) {
            l = mid + 1;
        } else if (xs[mid] > target) {
            h = mid - 1;
        } else {
            return true;
        }
    }

    return false;
}

#define MAX_N 100000
#define MAX_Q 50000

int main(void) {
    int n;
    int xs[MAX_N];
    int q;
    int count = 0;

    scanf("%d\n", &n);

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        xs[i] = x;
    }

    scanf("%d\n", &q);
    
    for (int i = 0; i < q; i++) {
        int y;
        scanf("%d", &y);

        if (binary_search(xs, n, y)) {
            // printf("%d\n", y);
            count++;
        }
    }
    
    printf("%d\n", count);

    return 0;
}

