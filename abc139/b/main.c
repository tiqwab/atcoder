#include <stdio.h>

int calc(int a, int b) {
    return ((b - 1) + (a - 2)) / (a - 1);
}

int main(void) {
    int a, b;

    scanf("%d %d", &a, &b);

    printf("%d\n", calc(a, b));

    return 0;
}
