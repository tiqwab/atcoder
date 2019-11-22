#include <stdio.h>
#include <string.h>

typedef long long ll;

#define min(a, b) ((a) < (b)) ? (a) : (b)
#define max(a, b) ((a) > (b)) ? (a) : (b)
#define swap(a, b, typ) \
    do { \
        typ tmp = a; \
        a = b; \
        b = tmp; \
    } while (0)

#define MAX_N 100

int main(void) {
    int n;
    char s1[MAX_N + 2], s2[MAX_N + 2];

    scanf("%d\n", &n);

    if (n % 2 == 1) {
        printf("No\n");
        return 0;
    }

    fgets(s1, n + 1, stdin);
    s1[n] = '\0';
    strncpy(s2, s1 + n / 2, n / 2 + 1);
    s1[n / 2] = '\0';

    if (strcmp(s1, s2) == 0) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}
