#include <math.h>
#include <stdio.h>

typedef long long ll;

#define MAX_N 100
#define DIST_TWICE(x) ((x[0]) * (x[0]) + (x[1]) * (x[1]))

int n;
ll rockets[MAX_N][2]; // 0: x, 1: y

int main(void) {
    scanf("%d\n", &n);

    for (int i = 0; i < n; i++) {
        ll x, y;
        scanf("%lld", &x);
        scanf("%lld", &y);
        rockets[i][0] = x;
        rockets[i][1] = y;
    }

    ll one[2] = {0, 0};
    ll two[2] = {0, 0};
    ll three[2] = {0, 0};
    ll four[2] = {0, 0};

    for (int i = 0; i < n; i++) {
        ll rkt_x = rockets[i][0];
        ll rkt_y = rockets[i][1];

        if (rkt_x > 0) {
            one[0] += rkt_x;
            two[0] += rkt_x;
        } else {
            three[0] += rkt_x;
            four[0] += rkt_x;
        }

        if (rkt_y > 0) {
            one[1] += rkt_y;
            four[1] += rkt_y;
        } else {
            two[1] += rkt_y;
            three[1] += rkt_y;
        }
    }

    ll max = DIST_TWICE(one);
    if (max < DIST_TWICE(two)) {
        max = DIST_TWICE(two);
    }
    if (max < DIST_TWICE(three)) {
        max = DIST_TWICE(three);
    }
    if (max < DIST_TWICE(four)) {
        max = DIST_TWICE(four);
    }

    printf("%11.11f\n", sqrt(max));

    return 0;
}
