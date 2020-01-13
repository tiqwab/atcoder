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

int main(void) {
    int N, K, M;
    cin >> N >> K >> M;

    int sum = 0;
    for (int i = 0; i < N - 1; i++) {
        int x;
        cin >> x;
        sum += x;
    }

    int ans = max(0, N * M - sum);
    if (ans > K) {
        cout << "-1" << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}
