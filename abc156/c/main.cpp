#include <algorithm>
#include <iostream>
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

vector<int> X;

int solve(const int N) {
    int ans = INF;

    for (int i = 0; i <= 100; i++) {
        int acc = 0;
        for (int j = 0; j < N; j++) {
            acc += (X[j] - i) * (X[j] - i);
        }
        chmin(ans, acc);
    }

    return ans;
}

int main(void) {
    int N;
    cin >> N;

    X.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> X[i];
    }

    cout << solve(N) << endl;

    return 0;
}
