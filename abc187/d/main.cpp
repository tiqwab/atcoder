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

// {aoki, takahashi};
vector<pair<int, int>> towns;

// {loss, index for towns}
vector<pair<ll, int>> loss_for_aoki;

int main(void) {
    int N;
    cin >> N;

    towns.resize(N);
    loss_for_aoki.resize(N);

    ll aoki_point = 0;
    ll takahashi_point = 0;

    for (int i = 0; i < N; i++) {
        ll a, b;
        cin >> a >> b;

        towns[i] = make_pair(a, b);

        loss_for_aoki[i] = make_pair(2 * a + b, i);

        aoki_point += towns[i].first;
    }

    sort(loss_for_aoki.begin(), loss_for_aoki.end());
    reverse(loss_for_aoki.begin(), loss_for_aoki.end());

    int ans = 0;
    for (auto &lfa : loss_for_aoki) {
        int idx = lfa.second;

        aoki_point -= towns[idx].first;
        takahashi_point += towns[idx].first + towns[idx].second;
        ans++;

        if (aoki_point < takahashi_point) {
            break;
        }
    }

    cout << ans << endl;

    return 0;
}
