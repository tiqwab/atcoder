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

const int INF = INT_MAX / 2;

vector<int> as;

int main(void) {
    int N;
    cin >> N;

    as.resize(N + 2);
    as[0] = INF;
    for (int i = 1; i <= N; i++) {
        cin >> as[i];
    }
    as[N + 1] = -INF;

    ll money = 1000;
    ll stock = 0;
    for (int i = 1; i <= N; i++) {
        if (as[i - 1] >= as[i] && as[i] < as[i + 1]) {
            // buy stocks
            stock += money / as[i];
            money = money % as[i];
            // printf("buy at %d: stock: %lld, money: %lld\n", i, stock, money);
        } else if (as[i - 1] <= as[i] && as[i] > as[i + 1]) {
            // sell stocks
            money += stock * as[i];
            stock = 0;
            // printf("sell at %d: stock: %lld, money: %lld\n", i, stock, money);
        }
    }

    cout << money << endl;

    return 0;
}
