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

int INF = INT_MAX / 2;

vector<pair<int, int>> ps;
vector<int> qs;
vector<int> rs;

int main(void) {
    int N;
    cin >> N;

    ps.resize(N);
    qs.resize(N);
    rs.resize(N);
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        ps[i] = make_pair(x, y);
        qs[i] = x + y;
        rs[i] = x - y;
    }

    int max_qs = *max_element(qs.begin(), qs.end());
    int min_qs = *min_element(qs.begin(), qs.end());
    int max_rs = *max_element(rs.begin(), rs.end());
    int min_rs = *min_element(rs.begin(), rs.end());

    cout << max(max_qs - min_qs, max_rs - min_rs) << endl;

    return 0;
}
