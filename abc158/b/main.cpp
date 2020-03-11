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
    ll N, A, B;
    cin >> N >> A >> B;

    ll cnt = N / (A + B);
    cout << A * cnt + min(A, N - cnt * (A + B)) << endl;

    return 0;
}
