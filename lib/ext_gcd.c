#include <stdio.h>

typedef long long ll;

/*
 * Return gcd(x, y).
 * x and y store values satisfying `ax + by = gcd(a, b)`
 * ref. https://qiita.com/drken/items/b97ff231e43bce50199a 
 */
ll ext_gcd(ll a, ll b, ll *x, ll *y) {
    if (b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }
    ll d = ext_gcd(b, a % b, y, x);
    *y = (*y) - a / b * (*x);
    return d;
}

int main(void) {
    ll x, y, d;
    d = ext_gcd(111, 30, &x, &y);
    printf("d = %d, x = %d, y = %d\n", d, x, y);
    return 0;
}
