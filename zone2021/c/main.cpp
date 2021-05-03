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

vector<int> as;
vector<int> bs;
vector<int> cs;
vector<int> ds;
vector<int> es;

typedef tuple<int, int, int, int, int> member;

bool h(const vector<member> &acc) {
    assert(((int) acc.size()) == 3);

    int a1, b1, c1, d1, e1;
    int a2, b2, c2, d2, e2;
    int a3, b3, c3, d3, e3;
    tie(a1, b1, c1, d1, e1) = acc[0];
    tie(a2, b2, c2, d2, e2) = acc[1];
    tie(a3, b3, c3, d3, e3) = acc[2];

    int a = max(max(a1, a2), a3);
    int b = max(max(b1, b2), b3);
    int c = max(max(c1, c2), c3);
    int d = max(max(d1, d2), d3);
    int e = max(max(e1, e2), e3);

    int ans = min(min(min(min(a, b), c), d), e);

    return ans == 1;
}

bool g(const int cur, const vector<member> members, vector<member> &acc) {
    if (((int) acc.size()) == 3) {
        return h(acc);
    }
    if (cur >= (int) members.size()) {
        return false;
    }

    bool ok = false;

    acc.push_back(members[cur]);
    ok = ok || g(cur + 1, members, acc);
    acc.pop_back();
    ok = ok || g(cur + 1, members, acc);

    return ok;
}

bool f(const int border, const int N) {
    vector<int> counter(1 << 5, 0);

    for (int i = 0; i < N; i++) {
        int x = 0;
        if (as[i] >= border) {
            x += 1 << 0;
        }
        if (bs[i] >= border) {
            x += 1 << 1;
        }
        if (cs[i] >= border) {
            x += 1 << 2;
        }
        if (ds[i] >= border) {
            x += 1 << 3;
        }
        if (es[i] >= border) {
            x += 1 << 4;
        }
        counter[x]++;
    }

    vector<member> members;

    for (int i = 0; i < (1 << 5); i++) {
        int cnt = min(counter[i], 3);
        for (int j = 0; j < cnt; j++) {
            int a, b, c, d, e;
            a = i & (1 << 0);
            b = i & (1 << 1);
            c = i & (1 << 2);
            d = i & (1 << 3);
            e = i & (1 << 4);
            members.push_back(tie(a, b, c, d, e));
        }
    }

    vector<member> acc;
    return g(0, members, acc);
}

int main(void) {
    int N;
    cin >> N;

    as.resize(N);
    bs.resize(N);
    cs.resize(N);
    ds.resize(N);
    es.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> as[i] >> bs[i] >> cs[i] >> ds[i] >> es[i];
    }

    int left = 1;
    int right = 1000 * 1000 * 1000 + 1;
    while (right - left > 1) {
        const int mid = left + (right - left) / 2;
        if (f(mid, N)) {
            left = mid;
        } else {
            right = mid;
        }
    }

    cout << left << endl;

    return 0;
}
