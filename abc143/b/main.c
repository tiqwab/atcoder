#include <stdio.h>

#define MAX_N 50

int main(void) {
    int n;
    int score[MAX_N];

    scanf("%d\n", &n);

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        score[i] = x;
    }

    int sum = 0;

    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            sum += score[i] * score[j];
        }
    }

    printf("%d\n", sum);

    return 0;
}
