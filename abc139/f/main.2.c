#include <math.h>
#include <stdio.h>

typedef long long ll;

#define MAX_N 100
#define DIST_TWICE(x, y) ((x) * (x) + (y) * (y))

int n;
ll rockets[MAX_N][2]; // 0: x, 1: y

ll one[2] = {0, 0};
ll two[2] = {0, 0};
ll three[2] = {0, 0};
ll four[2] = {0, 0};

void update(ll x, ll y) {
    if (x >= 0 && y >= 0) {
        if (DIST_TWICE(x, y) > DIST_TWICE(one[0], one[1])) {
            one[0] = x;
            one[1] = y;
        }
    }
    if (x >= 0 && y <= 0) {
        if (DIST_TWICE(x, y) > DIST_TWICE(two[0], two[1])) {
            two[0] = x;
            two[1] = y;
        }
    }
    if (x <= 0 && y <= 0) {
        if (DIST_TWICE(x, y) > DIST_TWICE(three[0], three[1])) {
            three[0] = x;
            three[1] = y;
        }
    }
    if (x <= 0 && y >= 0) {
        if (DIST_TWICE(x, y) > DIST_TWICE(four[0], four[1])) {
            four[0] = x;
            four[1] = y;
        }
    }
}

int main(void) {
    scanf("%d\n", &n);

    for (int i = 0; i < n; i++) {
        ll x, y;
        scanf("%lld", &x);
        scanf("%lld", &y);
        rockets[i][0] = x;
        rockets[i][1] = y;
    }

    for (int i = 0; i < n; i++) {
        ll rkt_x = rockets[i][0];
        ll rkt_y = rockets[i][1];
        ll old_one[2] = {one[0], one[1]};
        ll old_two[2] = {two[0], two[1]};
        ll old_three[2] = {three[0], three[1]};
        ll old_four[2] = {four[0], four[1]};
        ll x, y;

        x = old_one[0] + rkt_x;
        y = old_one[1] + rkt_y;
        update(x, y);

        x = old_two[0] + rkt_x;
        y = old_two[1] + rkt_y;
        update(x, y);

        x = old_three[0] + rkt_x;
        y = old_three[1] + rkt_y;
        update(x, y);

        x = old_four[0] + rkt_x;
        y = old_four[1] + rkt_y;
        update(x, y);
    }

    ll max = DIST_TWICE(one[0], one[1]);
    if (max < DIST_TWICE(two[0], two[1])) {
        max = DIST_TWICE(two[0], two[1]);
    }
    if (max < DIST_TWICE(three[0], three[1])) {
        max = DIST_TWICE(three[0], three[1]);
    }
    if (max < DIST_TWICE(four[0], four[1])) {
        max = DIST_TWICE(four[0], four[1]);
    }

    printf("%11.11f\n", sqrt(max));

    return 0;
}
