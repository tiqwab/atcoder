#include <algorithm>
#include <iostream>
#include <vector>

// ref. http://kmjp.hatenablog.jp/entry/2019/10/28/0900

using namespace std;

typedef long long ll;

const ll MAX_A = 1000000LL;
const ll MAX_F = 1000000LL;

bool cond(const vector<ll> &as, const vector<ll> &fs, const ll time, const ll k) {
    ll count = 0;

    for (int i = 0; i < (int) as.size(); i++) {
        ll v = as[i] * fs[i];
        if (v > time) {
            count += (v - time - 1 + fs[i]) / fs[i];
        }
        if (count > k) {
            return false;
        }
    }

    return true;
}

int main(void) {
    ll n, k;

    cin >> n >> k;

    vector<ll> as(n);
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        as[i] = x;
    }

    vector<ll> fs(n);
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        fs[i] = x;
    }

    sort(as.begin(), as.end());
    sort(fs.begin(), fs.end(), [](const int &a, const int &b) { return a > b; });

    // for (int i = 0; i < n; i++) {
    //     cout << as[i] << " ";
    // }
    // cout << endl;

    // for (int i = 0; i < n; i++) {
    //     cout << fs[i] << " ";
    // }
    // cout << endl;

    ll left = -1, right = MAX_A * MAX_F + 1;
    while (right - left > 1) {
        ll mid = (left + right) / 2;
        // cout << left << "," << mid << "," << right << endl;
        if (cond(as, fs, mid, k)) {
            right = mid;
        } else {
            left = mid;
        }
    }

    cout << right << endl;

    return 0;
}
