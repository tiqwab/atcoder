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
    int N, R;
    cin >> N >> R;

    int ans;
    if (N >= 10) {
        ans = R;
    } else {
        ans = R + 100 * (10 - N);
    }

    cout << ans << endl;
    
    return 0;
}
