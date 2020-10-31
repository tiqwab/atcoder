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

int main(void) {
    int N, M;
    cin >> N >> M;

    if (M < 0 || M > max(0, N - 2)) {
        cout << -1 << endl;
        return 0;
    }

    vector<pair<int, int>> areas(N);
    for (int i = 0; i < N; i++) {
        areas[i].first = i * 10 + 2;
        areas[i].second = i * 10 + 11;
    }

    if (M > 0) {
        areas[1].first = 1;
        areas[1].second = (M + 1) * 10 + 3;
    }

    for (int i = 0; i < N; i++) {
        printf("%d %d\n", areas[i].first, areas[i].second);
    }

    return 0;
}
