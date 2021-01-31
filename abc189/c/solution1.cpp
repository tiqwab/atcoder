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

vector<int> bars;

int ans = 0;

// [l, r)
void calc(const int l, const int r, const int h) {
    if (r - l == 0) {
        return;
    }

    chmax(ans, (r - l) * h);

    const int next_h = h + 1;
    int cur_r = r;
    for (int cur_l = r - 1; cur_l >= l; cur_l--) {
        if (bars[cur_l] < next_h) {
            calc(cur_l + 1, cur_r, next_h);
            cur_r = cur_l;
        }
    }
    if (cur_r != l) {
        calc(l, cur_r, next_h);
    }
}

int main(void) {
    int N;
    cin >> N;

    bars.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> bars[i];
    }

    calc(0, N, 1);
    cout << ans << endl;

    return 0;
}
