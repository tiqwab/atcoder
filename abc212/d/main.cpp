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

int main(void) {
    int Q;
    cin >> Q;

    auto f = [](const ll& one, const ll& other) {
        return one > other;
    };
    priority_queue<ll, vector<ll>, decltype(f)> que(f);


    ll acc = 0;

    for (int i = 0; i < Q; i++) {
        int op;
        cin >> op;
        if (op == 1) {
            ll x;
            cin >> x;
            que.push(x - acc);
        } else if (op == 2) {
            ll x;
            cin >> x;
            acc += x;
        } else {
            auto x = que.top();
            que.pop();
            printf("%lld\n", x + acc);
        }
    }

    return 0;
}
