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

vector<int> hs;
vector<int> ns;

int main(void) {
    int N, M;
    cin >> N >> M;

    hs.resize(N);
    ns.resize(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> hs[i];
    }

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        chmax(ns[a], hs[b]);
        chmax(ns[b], hs[a]);
    }

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (hs[i] > ns[i]) {
            cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}
