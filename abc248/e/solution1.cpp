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

int gcd(int x, int y) {
    if (y > x) {
        return gcd(y, x);
    }
    if (x == 0) {
        return y;
    }
    return gcd(y % x, x);
}

pair<int, int> normalize_slope(const int diff_x, const int diff_y) {
    const int g = gcd(abs(diff_x), abs(diff_y));

    if (diff_x > 0 && diff_y > 0) {
        return make_pair(diff_x / g, diff_y / g);
    } else if (diff_x > 0 && diff_y < 0) {
        return make_pair(diff_x / g, diff_y / g);
    } else if (diff_x < 0 && diff_y > 0) {
        return make_pair(abs(diff_x) / g, -1 * diff_y / g);
    } else {
        // diff_x < 0 && diff_y < 0
        return make_pair(abs(diff_x) / g, abs(diff_y) / g);
    }
}

bool check(const pair<int, int> v1, const pair<int, int> v2, const pair<int, int> cand) {
    const int diff_x = v1.first - v2.first;
    const int diff_y = v1.second - v2.second;

    const int diff_cand_x = v1.first - cand.first;
    const int diff_cand_y = v1.second - cand.second;

    if (diff_x == 0) {
        if (diff_cand_x != 0) {
            return false;
        }
        if (v1.first != cand.first) {
            return false;
        }
        return true;
    } else if (diff_y == 0) {
        if (diff_cand_y != 0) {
            return false;
        }
        if (v2.second != cand.second) {
            return false;
        }
        return true;
    } else {
        const pair<int, int> slope = normalize_slope(diff_x, diff_y);
        const pair<int, int> slope_cand = normalize_slope(diff_cand_x, diff_cand_y);
        if (slope.first != slope_cand.first || slope.second != slope_cand.second) {
            return false;
        }
        return true;
    }
}

int main(void) {
    int N, K;
    cin >> N >> K;

    vector<pair<int, int>> vertices;
    for (int i = 0 ; i < N; i++) {
        int x, y;
        cin >> x >> y;
        vertices.push_back(make_pair(x, y));
    }

    if (K == 1) {
        printf("Infinity\n");
        return 0;
    }

    int ans = 0;

    set<set<int>> groups;

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            set<int> group;
            auto v1 = vertices[i];
            auto v2 = vertices[j];
            group.insert(i);
            group.insert(j);

            int count = 2;

            for (int k = 0; k < N; k++) {
                if (k == i || k == j) {
                    continue;
                }
                if (check(v1, v2, vertices[k])) {
                    count++;
                    group.insert(k);
                }
            }

            if (count >= K) {
                if (groups.find(group) == groups.end()) {
                    ans += 1;
                    groups.insert(group);
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}
