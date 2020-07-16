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
    map<string, int> counter;

    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        counter[s]++;
    }

    int M;
    cin >> M;
    for (int i = 0; i < M; i++) {
        string t;
        cin >> t;
        counter[t]--;
    }

    int ans = 0;
    for (auto &p : counter) {
        chmax(ans, p.second);
    }

    cout << ans << endl;

    return 0;
}
