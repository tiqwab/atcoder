#include <algorithm>
#include <iostream>
#include <list>
#include <map>
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

const int MAX_N = 100000;
const int MAX_M = 100000;
const int MAX_S = MAX_N + 1;

int N, M;
char S[MAX_S + 10];
vector<int> res;

bool solve(int prev, int cur) {
    while (cur >= 0) {
        while (S[cur] == '1') {
            cur--;
        }
        if (prev - cur > M) return false;

        if (res[res.size() - 1] + prev - cur <= M) {
            res[res.size() - 1] += prev - cur;
        } else {
            res.push_back(prev - cur);
        }
        prev = cur;
        cur--;
    }

    return true;
}

int main(void) {
    cin >> N >> M;
    cin >> S;

    int prev = -1;
    res.push_back(0);
    for (int i = N - 1; i >= N - min(N, M); i--) {
        if (S[i] == '0') {
            prev = i;
            res[0] = N - i;
        }
    }
    if (prev < 0) {
        cout << -1 << endl;
        return 0;
    }

    if (solve(prev, N - min(N, M) - 1)) {
        reverse(res.begin(), res.end());
        cout << res[0];
        for (int i = 1; i < (int) res.size(); i++) {
            cout << " " << res[i];
        }
        cout << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
