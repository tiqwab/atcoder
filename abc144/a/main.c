#include <stdio.h>

int main(void) {
    int a, b;

    scanf("%d %d\n", &a, &b);
    if (a >= 10 || b >= 10) {
        fprintf(stdout, "-1\n");
    } else {
        fprintf(stdout, "%d\n", a * b);
    }

    return 0;
}
