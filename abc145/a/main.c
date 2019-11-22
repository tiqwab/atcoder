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

int main(void) {
    int r;
    scanf("%d\n", &r);
    printf("%d\n", r * r);

    return 0;
}
