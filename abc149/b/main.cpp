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
    ll A, B, K;
    cin >> A >> B >> K;

    ll taka = max(A - K, 0LL);
    ll ao = max(B - max(K - A, 0LL), 0LL);
    cout << taka << " " << ao << endl;

    return 0;
}
