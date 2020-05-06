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

vector<int> as;

vector<int> bs;
map<ll, int> cs;

int main(void) {
    int N;
    cin >> N;

    as.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> as[i];
    }

    bs.resize(N);
    for (int i = 0; i < N; i++) {
        bs[i] = i + 1 -  as[i];
    }

    for (int i = 0; i < N; i++) {
        cs[as[i] + i + 1]++;
    }

    ll cnt = 0;
    for (int i = 0; i < N; i++) {
        cnt += cs[bs[i]];
    }

    cout << cnt << endl;

    return 0;
}
