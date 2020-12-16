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
    int N, M;
    cin >> N >> M;

    as.push_back(0);
    for (int i = 0; i < M; i++) {
        int a;
        cin >> a;
        as.push_back(a);
    }
    as.push_back(N + 1);

    sort(as.begin(), as.end());

    int max_interval = INF;
    for (int i = 0; i < (int) as.size() - 1; i++) {
        int l = as[i];
        int r = as[i + 1];
        int interval = r - l - 1;
        if (interval > 0) {
            chmin(max_interval, interval);
        }
    }

    int ans = 0;
    for (int i = 0; i < (int) as.size() - 1; i++) {
        int l = as[i];
        int r = as[i + 1];
        int interval = r - l - 1;
        if (interval > 0) {
            ans += (interval + max_interval - 1) / max_interval;
        }
    }
    cout << ans << endl;

    return 0;
}
