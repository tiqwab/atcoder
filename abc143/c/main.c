#include <stdbool.h>
#include <stdio.h>

#define MAX_N 100000

int main(void) {
    int n;
    char s[MAX_N + 2];

    scanf("%d\n", &n);
    fgets(s, MAX_N + 2, stdin);

    while (true) {
        int i = 0;
        int j = 0;
        while (i < n - 1) {
            if (s[i] == s[i+1]) {
                s[j] = s[i++];
                while (s[j] == s[i] && i < n - 1) {
                    i++;
                }
                j++;
            } else {
                s[j++] = s[i++];
            }
        }
        if (s[n-2] != s[n-1]) {
            s[j++] = s[i++];
        }
        if (j == n) {
            printf("%d\n", n);
            break;
        }
        n = j;

        // printf("%d, %d, %d\n", i, j, n);
    }

    return 0;
}
