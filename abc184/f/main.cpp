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

vector<ll> xs;
vector<ll> ys;

vector<ll> values_xs;
vector<ll> values_ys;

void list_up(const vector<ll> &ns, vector<ll> &acc, const ll T) {
    const int l = (int) ns.size();
    for (int i = 0; i < (1 << l); i++) {
        ll v = 0;
        for (int j = 0; j < l; j++) {
            if (i & (1 << j)) {
                v += ns[j];
            }
        }
        if (v <= T) {
            acc.push_back(v);
        }
    }
}

int main(void) {
    int N;
    ll T;
    cin >> N >> T;

    for (int i = 0; i < N; i++) {
        ll a;
        cin >> a;
        if (i % 2 == 0) {
            xs.push_back(a);
        } else {
            ys.push_back(a);
        }
    }

    values_xs.push_back(T + 1);
    values_ys.push_back(T + 1);
    list_up(xs, values_xs, T);
    list_up(ys, values_ys, T);
    sort(values_xs.begin(), values_xs.end());
    sort(values_ys.begin(), values_ys.end());

#ifdef DEBUG
    printf("xs: \n");
    for (auto x : xs) {
        cout << x << " ";
    }
    printf("\n");

    printf("ys: \n");
    for (auto y : ys) {
        cout << y << " ";
    }
    printf("\n");

    printf("values_xs: \n");
    for (auto x : values_xs) {
        cout << x << " ";
    }
    printf("\n");

    printf("values_ys: \n");
    for (auto y : values_ys) {
        cout << y << " ";
    }
    printf("\n");
#endif

    ll ans = 0;
    for (auto x : values_xs) {
        if (x > T) {
            continue;
        }

        int left = 0, right = (int) values_ys.size();
        while (right - left > 1) {
            int mid = left + (right - left) / 2;
            if (x + values_ys[mid] <= T) {
                left = mid;
            } else {
                right = mid;
            }
        }
        chmax(ans, x + values_ys[left]);
    }

    cout << ans << endl;
    return 0;
}
