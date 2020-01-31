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
    int P, Q, R;
    cin >> P >> Q >> R;

    int x = P + Q;
    int y = Q + R;
    int z = R + P;

    cout << min(min(x, y), z) << endl;
    
    return 0;
}
