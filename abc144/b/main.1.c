#include <stdbool.h>
#include <stdio.h>

int main(void) {
    int n;
    bool multiples[100];

    scanf("%d\n", &n);

    for (int i = 0; i < 100; i++) {
        multiples[i] = false;
    }

    for (int i = 1; i < 10; i++) {
        for (int j = 1; j < 10; j++) {
            multiples[i * j] = true;
        }
    }

    if (multiples[n]) {
        fprintf(stdout, "Yes\n");
    } else {
        fprintf(stdout, "No\n");
    }

    return 0;
}
