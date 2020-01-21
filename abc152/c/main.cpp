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

vector<int> P;

int solve(const int N) {
    int m = INF;
    int count = 0;
    for (int i = 0; i < N; i++) {
        if (P[i] <= m) {
            count++;
            m = P[i];
        }
    }
    return count;
}

int main(void) {
    int N;
    cin >> N;

    P.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }

    cout << solve(N) << endl;

    return 0;
}
