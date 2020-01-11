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

    int sum1 = L * N  + (N * (N + 1) / 2) - N;
    int min = INF;
    int ans;
    for (int i = 1; i <= N; i++) {
        int sum2 = sum1 - (L + i - 1);
        if (abs(sum1 - sum2) < min) {
            min = abs(sum1 - sum2);
            ans = sum2;
        }
    }

    cout << ans << endl;

    return 0;
}
