#include <algorithm>
#include <iostream>
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

int binary_search(const vector<int> &xs, const int val, bool f(const vector<int> &, int, int)) {
    int left = -1, right = (int) xs.size(), mid;
    while (right - left > 1) {
        mid = left + (right - left) / 2; // (right + left) / 2 may cause overflow
        if (f(xs, mid, val)) right = mid;
        else left = mid;
    }

    return right;
}

/*
 * ref. https://atcoder.jp/contests/abc077/tasks/arc084_a
 */
int main(void) {
    int N;
    cin >> N;

    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    vector<int> b(N);
    for (int i = 0; i < N; i++) {
        cin >> b[i];
    }
    vector<int> c(N);
    for (int i = 0; i < N; i++) {
        cin >> c[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    ll ans = 0;
    for (int i_b = 0; i_b < N; i_b++) {
        // lower_bound (which returns the minimum index larger than or equal to val)
        int i_a = binary_search(a, b[i_b], [](const vector<int> &xs, int ind, int val) {
                return xs[ind] >= val;
        });
        // upper_bound (which returns the minimum index larger than val)
        int i_c = binary_search(c, b[i_b], [](const vector<int> &xs, int ind, int val) {
                return xs[ind] > val;
        });
        ans += ((ll) i_a) * ((ll) (c.size() - i_c));

        // Same as the above code
        // auto lb1 = lower_bound(a.begin(), a.end(), b[i_b]);
        // auto lb2 = upper_bound(c.begin(), c.end(), b[i_b]);
        // ans += (lb1 - a.begin()) * (c.end() - lb2);

        // cout <<i_a << "," << (((int) c.size()) - i_c) << " - "
        //     << (lb1 - a.begin()) << "," << (c.end() - lb2) << endl;
    }

    cout << ans << endl;
    
    return 0;
}
