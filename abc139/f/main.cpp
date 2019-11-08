#include <algorithm>
#include <vector>

#include <math.h>
#include <stdio.h>

/*
 * ref. https://qiita.com/ganariya/items/adef1a7f89ae88b804da
 */

using namespace std;

typedef long long ll;

#define MAX_N 100
#define DIST_TWICE(x, y) ((x) * (x) + (y) * (y))

class Point {
    public:
        ll x;
        ll y;
};

int n;
vector<Point> rockets(MAX_N * 2);

int main(void) {
    scanf("%d\n", &n);

    for (int i = 0; i < n; i++) {
        ll x, y;
        scanf("%lld", &x);
        scanf("%lld", &y);
        rockets[i].x = x;
        rockets[i].y = y;
    }

    sort(&rockets[0], &rockets[n], [](const Point &a, const Point &b) {
            return atan2(a.y, a.x) < atan2(b.y, b.x);
    });

    for (int i = 0; i < n; i++) {
        rockets[n + i] = rockets[i];
    }

    ll max = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < i + 1 + n; j++) {
            // printf("%d, %d\n", i, j);

            Point acc;
            acc.x = 0;
            acc.y = 0;
            for (int k = i; k < j; k++) {
                acc.x += rockets[k].x;
                acc.y += rockets[k].y;
            }

            // printf("acc: %lld\n", DIST_TWICE(acc.x, acc.y));

            if (DIST_TWICE(acc.x, acc.y) > max) {
                max = DIST_TWICE(acc.x, acc.y);
            }
        }
    }

    printf("%11.11f\n", sqrt(max));

    return 0;
}
