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

double calc(int x, const double K) {
    double possibility = 1;
    while (x < K) {
        x *= 2;
        possibility *= 0.5;
    }
    return possibility;
}

int main(void) {
    int N, K;
    cin >> N >> K;

    double acc = 0;
    for (int i = 1; i <= N; i++) {
        acc += 1.0 / double(N) * calc(i, K);
    }

    printf("%.10f\n", acc);

    return 0;
}
