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

// solution based on the pdf: https://img.atcoder.jp/abc161/editorial.pdf.
int main(void) {
    ll K;
    cin >> K;

    queue<ll> q;
    for (int i = 1; i <= 9; i++) {
        q.push(i);
    }

    int cnt = 0;

    while (true) {
        ll x = q.front();
        q.pop();
        cnt++;
        // printf("%lld\n", x);

        if (cnt == K) {
            cout << x << endl;
            break;
        }

        int d = x % 10;
        x *= 10;

        if (d > 0) {
            q.push(x + d - 1);
        }

        q.push(x + d);

        if (d < 9) {
            q.push(x + d + 1);
        }
    }

    return 0;
}
