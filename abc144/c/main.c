#include <math.h>
#include <stdio.h>
#include <limits.h>

int main(void) {
    long long n, m;
    long long minimum = LLONG_MAX;

    scanf("%lld\n", &n);

    m = (long long) sqrt(n);

    for (long long i = 1; i <= m; i++) {
        long long a, b;
        if (n % i == 0) {
            a = n / i;
            b = (i - 1) + (a - 1);
            if (b < minimum) {
                minimum = b;
            }
        }
    }

    fprintf(stdout, "%lld\n", minimum);

    return 0;
}
