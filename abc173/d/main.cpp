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

vector<ll> as;

int main(void) {
    int N;
    cin >> N;

    as.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> as[i];
    }
    sort(as.begin(), as.end());
    reverse(as.begin(), as.end());

    queue<ll> pq;
    pq.push(as[0]);

    ll ans = 0;
    for (int i = 1; i < N; i++) {
        ll v = pq.front();
        pq.pop();

        ans += v;
        pq.push(as[i]);
        pq.push(as[i]);
    }


    cout << ans << endl;

    return 0;
}
