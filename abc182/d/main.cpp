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

const ll INF = LONG_LONG_MAX / 2;

vector<ll> as;
vector<ll> ss;
vector<ll> ts;

int main(void) {
    int N;
    cin >> N;

    as.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> as[i];
    }

    ss.resize(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        ss[i] = ss[i - 1] + as[i - 1];
    }

    ts.resize(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        ts[i] = max(ts[i - 1], ss[i]);
    }

#ifdef DEBUG
    printf("ss: \n");
    for (int i = 0; i <= N; i++) {
        cout << ss[i] << " ";
    }
    cout << endl;
#endif

#ifdef DEBUG
    printf("ts: \n");
    for (int i = 0; i <= N; i++) {
        cout << ts[i] << " ";
    }
    cout << endl;
#endif

    ll ans = -INF;
    ll acc = 0;
    for (int i = 0; i < N; i++) {
        acc += ss[i];
        chmax(ans, acc + ts[i + 1]);
    }

    cout << ans << endl;
    return 0;
}
