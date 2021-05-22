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

    vector<pair<int, string>> ms(N, make_pair(0, ""));

    for (int i = 0; i < N; i++) {
        string s;
        int t;
        cin >> s >> t;
        ms[i] = make_pair(t, s);
    }
    sort(ms.rbegin(), ms.rend());

    cout << ms[1].second << endl;

    return 0;
}
