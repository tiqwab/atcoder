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

const int MAX_TIME = 1000 * 1000;

vector<int> ts;

vector<bool> dp;

int main(void) {
    int N;
    cin >> N;

    int sum = 0;

    ts.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> ts[i];
        sum += ts[i];
    }

    dp.resize(MAX_TIME, false);
    dp[0] = true;

    for (int i = 0; i < N; i++) {
        for (int j = MAX_TIME - 1; j >= 0; j--) {
            if (dp[j]) {
                dp[j + ts[i]] = true;
            }
        }
    }

    int ans = MAX_TIME;

    for (int i = 0; i < MAX_TIME; i++) {
        if (dp[i]) {
            chmin(ans, max(i, sum - i)); 
        }
    }

    cout << ans << endl;

    return 0;
}
