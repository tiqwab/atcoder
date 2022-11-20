#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

#include <limits.h>

#include <atcoder/all>
using namespace atcoder;

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

const int CHOCO = 1;
const int BOX = 2;

vector<int> as;
vector<int> bs;
vector<int> cs;
vector<int> ds;

int main(void) {
    int N, M;
    cin >> N >> M;

    as.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> as[i];
    }

    bs.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> bs[i];
    }

    cs.resize(M);
    for (int i = 0; i < M; i++) {
        cin >> cs[i];
    }

    ds.resize(M);
    for (int i = 0; i < M; i++) {
        cin >> ds[i];
    }

    // {tate, yoko, type}
    vector<tuple<int, int, int>> ts;

    for (int i = 0; i < N; i++) {
        ts.push_back(make_tuple(as[i], bs[i], CHOCO));
    }
    for (int i = 0; i < M; i++) {
        ts.push_back(make_tuple(cs[i], ds[i], BOX));
    }
    sort(ts.begin(), ts.end());
    reverse(ts.begin(), ts.end());

    // {yoko}
    multiset<int> ss;

    bool ok = true;

    for (int i = 0; i < N + M; i++) {
        int tate, yoko, type;
        auto t = ts[i];
        tie(tate, yoko, type) = t;

        if (type == BOX) {
            ss.insert(yoko);
        } else {
            auto it = ss.lower_bound(yoko);
            if (it == ss.end()) {
                ok = false;
                break;
            }
            ss.erase(it);
        }
    }

    if (ok) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}
