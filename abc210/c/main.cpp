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

int main(void) {
    int N, K;
    cin >> N >> K;

    vector<int> cs(N);
    for (int i = 0; i < N; i++) {
        cin >> cs[i];
    }

    map<int, int> counter;

    for (int i = 0; i < K - 1; i++) {
        counter[cs[i]]++;
    }

    int ans = 0;
    for (int i = K - 1; i < N; i++) {
        counter[cs[i]]++;
        // cout << counter.size() << endl;
        chmax(ans, (int) counter.size());
        counter[cs[i - K + 1]]--;
        if (counter[cs[i - K + 1]] == 0) {
            counter.erase(cs[i - K + 1]);
        }
    }

    cout << ans << endl;

    return 0;
}
