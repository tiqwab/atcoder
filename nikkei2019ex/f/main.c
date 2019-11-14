#include <stdbool.h>
#include <stdio.h>

typedef long long ll;

#define min(a, b) ((a) < (b)) ? (a) : (b)
#define max(a, b) ((a) > (b)) ? (a) : (b)
#define swap(a, b, typ) \
    do { \
        typ tmp = a; \
        a = b; \
        b = tmp; \
    } while (0)

void solve(int x) {
    char buf[6];
    int index = 0;

    if (x % 2 == 0) {
        buf[index++] = 'a';
    }
    if (x % 3 == 0) {
        buf[index++] = 'b';
    }
    if (x % 4 == 0) {
        buf[index++] = 'c';
    }
    if (x % 5 == 0) {
        buf[index++] = 'd';
    }
    if (x % 6 == 0) {
        buf[index++] = 'e';
    }

    buf[index] = '\0';

    if (index == 0) {
        printf("%d\n", x);
    } else {
        printf("%s\n", buf);
    }
}

int main(void) {
    int n;

    scanf("%d\n", &n);

    for (int i = 1; i <= n; i++) {
        solve(i);
    }

    return 0;
}
