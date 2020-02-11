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

vector<ll> p;

double solve(const int N, const int K) {
    double acc = 0;
    double maximum = 0;
    for (int i = 0; i < K; i++) {
        acc += (1 + p[i]) / 2.0;
    }
    maximum = acc;

    for (int i = K; i < N; i++) {
        acc -= (1 + p[i - K]) / 2.0;
        acc += (1 + p[i]) / 2.0;
        chmax(maximum, acc);
    }

    return double(maximum);
}

int main(void) {
    int N, K;
    cin >> N >> K;

    p.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> p[i];
    }

    printf("%.7f\n", solve(N, K));

    return 0;
}
