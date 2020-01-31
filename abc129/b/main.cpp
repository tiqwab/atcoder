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

int main(void) {
    int N;
    cin >> N;

    int acc = 0;
    vector<int> W(N);
    for (int i = 0; i < N; i++) {
        cin >> W[i];
        acc += W[i];
    }

    int x = 0, y = acc, m = INF;
    for (int i = 0; i < N; i++) {
        x += W[i];
        y -= W[i];
        chmin(m, abs(x - y));
    }

    cout << m << endl;

    return 0;
}
