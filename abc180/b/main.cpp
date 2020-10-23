#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

#include <limits.h>
#include <math.h>

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
    int N;
    cin >> N;

    vector<ll> xs(N);
    for (int i = 0; i < N; i++) {
        cin >> xs[i];
    }

    {
        ll ans = 0;
        for (int i = 0; i < N; i++) {
            ans += abs(xs[i]);
        }
        cout << ans << endl;
    }

    {
        ll ans = 0;
        for (int i = 0; i < N; i++) {
            ans += xs[i] * xs[i];
        }
        printf("%.10f\n", sqrt((double) ans));
    }

    {
        ll ans = 0;
        for (int i = 0; i < N; i++) {
            chmax(ans, abs(xs[i]));
        }
        cout << ans << endl;
    }

    return 0;
}
