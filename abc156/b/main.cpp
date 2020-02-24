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

int solve(int n, const int K) {
    int ans = 0;
    while (n > 0) {
        ans++;
        n /= K;
    }
    return ans;
}

int main(void) {
    int N, K;
    cin >> N >> K;

    cout << solve(N, K) << endl;

    return 0;
}
