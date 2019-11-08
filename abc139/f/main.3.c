#include <math.h>
#include <stdio.h>

typedef long long ll;

#define MAX_N 100
#define DIST_TWICE(x, y) ((x) * (x) + (y) * (y))

int n;
ll rockets[MAX_N][2]; // 0: x, 1: y

ll one[MAX_N][2];
ll two[MAX_N][2];
ll three[MAX_N][2];
ll four[MAX_N][2];

void update(ll x, ll y, int i) {
    if (x >= 0 && y >= 0) {
        if (DIST_TWICE(x, y) > DIST_TWICE(one[i][0], one[i][1])) {
            one[i][0] = x;
            one[i][1] = y;
        }
    }
    if (x >= 0 && y <= 0) {
        if (DIST_TWICE(x, y) > DIST_TWICE(two[i][0], two[i][1])) {
            two[i][0] = x;
            two[i][1] = y;
        }
    }
    if (x <= 0 && y <= 0) {
        if (DIST_TWICE(x, y) > DIST_TWICE(three[i][0], three[i][1])) {
            three[i][0] = x;
            three[i][1] = y;
        }
    }
    if (x <= 0 && y >= 0) {
        if (DIST_TWICE(x, y) > DIST_TWICE(four[i][0], four[i][1])) {
            four[i][0] = x;
            four[i][1] = y;
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

    update(rockets[0][0], rockets[0][1], 0);

    for (int i = 1; i < n; i++) {
        ll rkt_x = rockets[i][0];
        ll rkt_y = rockets[i][1];
        ll x, y;

        one[i][0] = one[i-1][0];
        one[i][1] = one[i-1][1];
        two[i][0] = two[i-1][0];
        two[i][1] = two[i-1][1];
        three[i][0] = three[i-1][0];
        three[i][1] = three[i-1][1];
        four[i][0] = four[i-1][0];
        four[i][1] = four[i-1][1];

        for (int j = 0; j < i; j++) {
            x = one[j][0] + rkt_x;
            y = one[j][1] + rkt_y;
            update(x, y, i);

            x = two[j][0] + rkt_x;
            y = two[j][1] + rkt_y;
            update(x, y, i);

            x = three[j][0] + rkt_x;
            y = three[j][1] + rkt_y;
            update(x, y, i);

            x = four[j][0] + rkt_x;
            y = four[j][1] + rkt_y;
            update(x, y, i);
        }
    }

    ll max = DIST_TWICE(one[n-1][0], one[n-1][1]);
    if (max < DIST_TWICE(two[n-1][0], two[n-1][1])) {
        max = DIST_TWICE(two[n-1][0], two[n-1][1]);
    }
    if (max < DIST_TWICE(three[n-1][0], three[n-1][1])) {
        max = DIST_TWICE(three[n-1][0], three[n-1][1]);
    }
    if (max < DIST_TWICE(four[n-1][0], four[n-1][1])) {
        max = DIST_TWICE(four[n-1][0], four[n-1][1]);
    }

    printf("%11.11f\n", sqrt(max));

    return 0;
}
