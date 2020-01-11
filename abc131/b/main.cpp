#include <algorithm>
#include <iostream>
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

const int INF = 1001001000;

int main(void) {
    int N, L;
    cin >> N >> L;

    int sum = L * N  + (N * (N + 1) / 2) - N;
    int a = L + 1 - 1;
    int b = L + N - 1;

    if (a > 0) {
        // should remove apple 1.
        cout << sum - a << endl;
    } else if (b < 0) {
        // should remove apple N.
        cout << sum - b << endl;
    } else {
        // there is an apple whose value is 0. so output the same value.
        cout << sum << endl;
    }

    return 0;
}
