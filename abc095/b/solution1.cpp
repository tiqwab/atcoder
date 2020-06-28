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
    int N, X;
    cin >> N >> X;

    vector<int> ms(N);
    for (int i = 0; i < N; i++) {
        cin >> ms[i];
    }
    sort(ms.begin(), ms.end());

    int cnt = 0;
    int rem = X;
    for (auto &m : ms) {
        rem -= m;
        cnt++;
    }

    while (rem - ms[0] >= 0) {
        rem -= ms[0];
        cnt++;
    }

    cout << cnt << endl;

    return 0;
}
