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

const int INF = INT_MAX / 2;

vector<int> acc_e;
vector<int> acc_w;

int main(void) {
    int N;
    cin >> N;
    string S;
    cin >> S;
    const int slen = (int) S.size();

    acc_e.resize(slen + 1, 0);
    acc_w.resize(slen + 1, 0);

    for (int i = 0; i < slen; i++) {
        acc_e[i + 1] = acc_e[i];
        acc_w[i + 1] = acc_w[i];
        if (S[i] == 'E') {
            acc_e[i + 1] += 1;
        } else {
            acc_w[i + 1] += 1;
        }
    }

    int ans = INF;

    for (int i = 0; i < N; i++) {
        chmin(ans, acc_w[i] + (acc_e[slen] - acc_e[i + 1]));
    }

    cout << ans << endl;

    return 0;
}
