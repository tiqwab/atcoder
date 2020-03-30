#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

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

map<int, int> dists;

void solve(const int N, const int X, const int Y) {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            // i to j
            int d1 = abs(i - j);
            int d2 = abs(i - X) + 1 + abs(j - Y); // use bipass from X
            int d3 = abs(i - Y) + 1 + abs(j - X); // use bipass from Y
            int d = min(min(d1, d2), d3);
            dists[d]++;
        }
    }
}

int main(void) {
    int N, X, Y;
    cin >> N >> X >> Y;

    solve(N, X, Y);

    for (int i = 1; i <= N - 1; i++) {
        cout << dists[i] / 2 << endl;
    }

    return 0;
}
