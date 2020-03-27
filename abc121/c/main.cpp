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

// {price, num}
vector<pair<ll, ll>> shops;

int main(void) {
    int N, M;
    cin >> N >> M;

    shops.resize(N);
    for (int i = 0; i < N; i++) {
        ll a, b;
        cin >> a >> b;
        shops[i] = {a, b};
    }
    sort(shops.begin(), shops.end());

    ll cnt = 0;
    ll sum_price = 0;
    for (int i = 0; i < N; i++) {
        auto shop = shops[i];
        if (cnt + shop.second >= M) {
            ll require_cnt = M - cnt;
            sum_price += require_cnt * shop.first;
            break;
        } else {
            sum_price += shop.first * shop.second;
            cnt += shop.second;
        }
    }

    cout << sum_price << endl;

    return 0;
}
