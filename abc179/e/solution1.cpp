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

ll f(const ll x, const ll m) {
    return ((x % m) * (x % m)) % m;
}

int main(void) {
    ll N, X, M;
    cin >> N >> X >> M;

    if (X == 0) {
        cout << 0 << endl;
        return 0;
    }

    vector<ll> as;
    as.push_back(X);

    set<ll> appeared;
    appeared.insert(X);

    bool has_loop = false;
    int loop_start = -1;
    bool has_zero = false;
    bool has_one = false;

    for (int i = 1; i < N; i++) {
        ll a = f(as.back(), M);
        if (a == 0) {
            has_zero = true;
            break;
        } else if (a == 1) {
            has_one = true;
            break;
        } else {
            if (appeared.find(a) != appeared.end()) {
                has_loop = true;
                for (int i = 0; i < (int) as.size(); i++) {
                    if (as[i] == a) {
                        loop_start = i;
                    }
                }
                assert(loop_start >= 0);
                break;
            }
        }
        as.push_back(a);
        appeared.insert(a);
    }

    ll sum_as = 0;
    for (auto a : as) {
        sum_as += a;
    }

    ll ans = 0;
    if (has_zero) {
        ans += sum_as;
    } else if (has_one) {
        ans += sum_as;
        ans += N - ((ll) as.size());
    } else if (has_loop) {
        ll sum_loop = sum_as;
        for (int i = 0; i < loop_start; i++) {
            ans += as[i];
            sum_loop -= as[i];
        }
        ll size_loop = ((ll) as.size()) - loop_start;

        ll remain_num = N - loop_start;
        ans += sum_loop * (remain_num / size_loop);
        for (int i = 0; i < remain_num % size_loop; i++) {
            ans += as[loop_start + i];
        }
    } else {
        ans += sum_as;
    }

    cout << ans << endl;
    return 0;
}
