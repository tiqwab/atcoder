#include <stdio.h>

int main(void) {
    int a, b;

    scanf("%d %d", &a, &b);

    if (a - 2 * b > 0) {
        printf("%d\n", a - 2 * b);
    } else {
        printf("%d\n", 0);
    }

    return 0;
}
