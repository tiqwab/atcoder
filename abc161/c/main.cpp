#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <queue>
#include <set>
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
    ll N, K;
    cin >> N >> K;

    ll a = N % K;
    ll b = abs(a - K);
    // printf("%lld, %lld\n", a, b);

    cout << min(a, b) << endl;
    
    return 0;
}
