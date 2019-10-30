#include <stdio.h>

int main(void) {
    int n;

    scanf("%d\n", &n);

    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            if (i * j == n) {
                fprintf(stdout, "Yes\n");
                return 0;
            }
        }
    }

    fprintf(stdout, "No\n");
    return 0;
}
