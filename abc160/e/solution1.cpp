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

vector<ll> ps;
vector<ll> qs;
vector<ll> rs;

vector<ll> all;

int main(void) {
    ll X, Y, A, B, C;
    cin >> X >> Y >> A >> B >> C;

    ps.resize(A);
    for (int i = 0; i < A; i++) {
        cin >> ps[i];
    }

    qs.resize(B);
    for (int i = 0; i < B; i++) {
        cin >> qs[i];
    }

    rs.resize(C);
    for (int i = 0; i < C; i++) {
        cin >> rs[i];
    }

    sort(ps.begin(), ps.end());
    reverse(ps.begin(), ps.end());
    sort(qs.begin(), qs.end());
    reverse(qs.begin(), qs.end());

    for (int i = 0; i < min(A, X); i++) {
        all.push_back(ps[i]);
    }

    for (int i = 0; i < min(B, Y); i++) {
        all.push_back(qs[i]);
    }
    for (int i = 0; i < C; i++) {
        all.push_back(rs[i]);
    }

    sort(all.begin(), all.end());
    reverse(all.begin(), all.end());

    ll ans = 0;
    for (int i = 0; i < X + Y; i++) {
        ans += all[i];
    }

    cout << ans << endl;

    return 0;
}
