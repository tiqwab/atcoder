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
    int N;
    cin >> N;

    vector<int> as(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> as[i];
    }

    int ans = 0;

    for (int i = 1; i <= N; i++) {
        if (i % 2 == 1 && as[i] % 2 == 1) {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
