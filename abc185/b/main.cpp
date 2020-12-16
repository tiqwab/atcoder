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

vector<pair<int, int>> ms;

int main(void) {
    int N, M, T;
    cin >> N >> M >> T;

    ms.resize(M + 1);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        ms[i] = make_pair(a, b);
    }
    ms[M] = make_pair(T, T);

    bool ok = true;
    int time = 0;
    int vattery = N;
    for (int i = 0; i <= M; i++) {
        int left = ms[i].first;
        int right = ms[i].second;
        vattery -= left - time;
        time = left;
        // printf("time: %d, vattery: %d, left: %d, right: %d\n", time, vattery, left, right);

        if (vattery <= 0) {
            ok = false;
            break;
        }

        vattery = min(N, vattery + right - left);
        time = right;
    }

    if (ok) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
