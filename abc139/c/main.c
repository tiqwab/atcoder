#include <stdio.h>

#define MAX_N 100000

int main(void) {
    int n;
    int h[MAX_N];
    int score[MAX_N];
    int largest = 0;

    scanf("%d\n", &n);

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        h[i] = x;
    }

    score[n-1] = 0;

    for (int i = n-2; i >= 0; i--) {
        if (h[i] >= h[i+1]) {
            score[i] = score[i+1] + 1;
        } else {
            score[i] = 0;
        }

        if (score[i] > largest) {
            largest = score[i];
        }
    }

    printf("%d\n", largest);

    return 0;
}
