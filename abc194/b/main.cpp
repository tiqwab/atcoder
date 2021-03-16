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

int main(void) {
    int N;
    cin >> N;

    vector<int> as(N);
    vector<int> bs(N);
    for (int i = 0; i < N; i++) {
        cin >> as[i] >> bs[i];
    }

    int ans = INF;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) {
                chmin(ans, as[i] + bs[j]);
            } else {
                chmin(ans, max(as[i], bs[j]));
            }
        }
    }

    cout << ans << endl;

    return 0;
}
