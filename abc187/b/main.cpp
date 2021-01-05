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

vector<pair<int, int>> ps;

int main(void) {
    int N;
    cin >> N;

    ps.resize(N);
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        ps[i] = make_pair(x, y);
    }

    int ans = 0;

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            pair<int, int> a = ps[i];
            pair<int, int> b = ps[j];
            // should be a.x >= b.x
            if (a.first < b.first) {
                swap(a, b);
            }

            int diff_x = a.first - b.first;
            int diff_y = a.second - b.second;

            if (diff_y >= - 1 * diff_x && diff_y <= diff_x) {
                ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
