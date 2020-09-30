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

    vector<pair<int, int>> ds(N);
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        ds[i] = make_pair(a, b);
    }

    int cur_succ_cnt = 0;
    int max_succ_cnt = 0;
    for (int i = 0; i < N; i++) {
        if (ds[i].first == ds[i].second) {
            cur_succ_cnt++;
        } else {
            cur_succ_cnt = 0;
        }
        chmax(max_succ_cnt, cur_succ_cnt);
    }

    if (max_succ_cnt >= 3) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
