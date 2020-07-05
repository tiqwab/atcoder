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

// ref. https://drken1215.hatenablog.com/entry/2018/09/08/195000
int main(void) {
    int Q;
    cin >> Q;

    for (int i = 0; i < Q; i++) {
        ll a, b;
        cin >> a >> b;

        if (a > b) {
            swap(a, b);
        }

        if (a == b) {
            cout << 2 * (a - 1) << endl;
            continue;
        }

        ll left = 1, right = 1LL << 31, mid;
        while (right - left > 1) {
            mid = left + (right - left) / 2;

            // this condition is simpler
            if (((mid + 1) / 2) * ((mid + 1) - (mid + 1) / 2) < a * b) {

            // this conditon is complicated, but understandable.
            // ll m = (mid + 1) - a + 1;
            // ll n = (mid + 1) - b + 1;
            // if (((mid + 1) / 2) * ((mid + 1) - (mid + 1) / 2) < a * b
            //         && (m * n < a * b || (n == a && m == b))) {
                left = mid;
            } else {
                right = mid;
            }
        }

        // why -1?
        cout << left - 1 << endl;
    }

    return 0;
}
