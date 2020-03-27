#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <queue>
#include <set>
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

int main(void) {
    int N, M, C;
    cin >> N >> M >> C;

    vector<int> bs(M, 0);
    for (int i = 0; i < M; i++) {
        cin >> bs[i];
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        int acc = 0;
        for (int j = 0; j < M; j++) {
            int x;
            cin >> x;
            acc += bs[j] * x;
        }

        if (acc + C > 0) {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
