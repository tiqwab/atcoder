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

const int INF = INT_MAX / 2;

vector<int> as;

int main(void) {
    int N;
    cin >> N;

    as.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> as[i];
    }
    sort(as.begin(), as.end());

    {
        int n = as.back();

        /* solution 1 */
        // int k = -INF;
        // for (int i = 0; i < N - 1; i++) {
        //     if (n % 2 == 0 &&
        //             (abs(n / 2 - as[i]) < abs(n / 2 - k))) {
        //         k = as[i];
        //     }
        //     if (n % 2 == 1 &&
        //             (abs(n / 2 - as[i]) < abs(n / 2 - k) || abs(n / 2 + 1 - as[i]) < abs(n / 2 + 1 - k))) {
        //         k = as[i];
        //     }
        // }

        /* solution 2 */
        auto it = lower_bound(as.begin(), as.end() - 1, n / 2);
        assert(it != as.end());
        int cand1 = *it;
        int cand2 = *(--it);
        int k = (cand1 < n - cand2) ? cand1 : cand2;

        cout << n << " " << k << endl;
    }

    return 0;
}
