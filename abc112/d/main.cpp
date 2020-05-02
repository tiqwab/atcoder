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

vector<ll> calc_divs(ll M) {
    vector<ll> divs;
    divs.push_back(1LL);
    divs.push_back(M);
    for (int i = 2; i * i <= M; i++) {
        if (M % i == 0) {
            divs.push_back(ll(i));
            if (i * i != M) divs.push_back(ll(M / i));
        }
    }
    sort(divs.begin(), divs.end());
    return divs;
}

int main(void) {
    ll N, M;
    cin >> N >> M;

    vector<ll> divs = calc_divs(M);
    reverse(divs.begin(), divs.end());
    int ans = -1;
    for (int i = 0; i < (int) divs.size(); i++) {
        // printf("divs: %lld\n", divs[i]);
        if (divs[i] * N <= M) {
            ans = divs[i];
            break;
        }
    }

    cout << ans << endl;

    return 0;
}
