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
    int A, B;
    cin >> A >> B;

    int ans;
    if (A >= 13) {
        ans = B;
    } else if (A >= 6 && A <= 12) {
        ans = B / 2;
    } else {
        ans = 0;
    }

    cout << ans << endl;

    return 0;
}
