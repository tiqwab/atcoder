#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

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

/*
 * Longest Increasing Subsequences
 * ref. http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D&lang=jp
 * ref. http://tutuz.hateblo.jp/entry/2018/06/18/214827
 */
int main(void) {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // (value, count)
    deque<int> q;
    for (int i = 0; i < n; i++) {
        auto it = lower_bound(q.begin(), q.end(), a[i]);
        if (it == q.end()) {
            q.push_back(a[i]);
        } else {
            q[it - q.begin()] = a[i];
        }
    }

    cout << q.size() << endl;

    return 0;
}
