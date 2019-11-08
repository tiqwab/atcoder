#include <stdio.h>

typedef long long ll;

int main(void) {
    ll n;
    ll answer;

    scanf("%lld", &n);

    answer = (n * (n - 1)) / 2;
    printf("%lld\n", answer);

    return 0;
}
