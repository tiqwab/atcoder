#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

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

    for (int i = 0; i < n; i++) {
        cout << as[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < n; i++) {
        cout << fs[i] << " ";
    }
    cout << endl;

    int a_ind = 0;
    while (k > 0 && a_ind < n) {
        if (as[a_ind] > 0) {
            as[a_ind]--;
            if (as[a_ind] == 0) {
                a_ind++;
            }
            k--;
        }
    }

    ll res = 0;
    for (int i = 0; i < n; i++) {
        res += as[i] * fs[i];
    }

    cout << res << endl;

    return 0;
}
