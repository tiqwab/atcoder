#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

#include <limits.h>

using namespace std;

typedef long long ll;

template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

vector<pair<int, int>> towns;

int calc_gcd(const int x, const int y) {
    if (x > y) {
        return calc_gcd(y, x);
    }
    if (x == 0) {
        return y;
    }
    return calc_gcd(y % x, x);
}

int main(void) {
    int N;
    cin >> N;

    towns.resize(N);
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        towns[i] = make_pair(x, y);
    }

    sort(towns.begin(), towns.end());

    set<pair<int, int>> slopes;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            // towns[i].x <= towns[j].x
            const int diff_x = towns[j].first - towns[i].first;
            const int diff_y = towns[j].second - towns[i].second;

            // printf("diff_x: %d, diff_y: %d\n", diff_x, diff_y);

            if (diff_x == 0) {
                slopes.insert(make_pair(0, 1));
            } else if (diff_y == 0) {
                slopes.insert(make_pair(1, 0));
            } else {
                const int gcd = calc_gcd(abs(diff_x), abs(diff_y));
                slopes.insert(make_pair(diff_x / gcd, diff_y / gcd));
            }
        }
    }

#ifdef DEBUG
    for (auto p : slopes) {
        printf("%d %d\n", p.first, p.second);
    }
#endif

    cout << slopes.size() * 2 << endl;

    return 0;
}
