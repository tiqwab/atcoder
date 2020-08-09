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

    int nr = 0;
    int nw = 0;

    vector<char> cs(N);
    for (int i = 0; i < N; i++) {
        cin >> cs[i];
        if (cs[i] == 'R') {
            nr++;
        } else {
            nw++;
        }
    }

    vector<char> expected(N);
    for (int i = 0; i < nr; i++) {
        expected[i] = 'R';
    }
    for (int i = nr; i < N; i++) {
        expected[i] = 'W';
    }

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (cs[i] != expected[i]) {
            cnt++;
        }
    }

    // printf("cnt: %d\n", cnt);
    assert(cnt % 2 == 0);
    cout << cnt / 2 << endl;

    return 0;
}
