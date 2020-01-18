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
    int N1, N2, N3, N4;
    cin >> N1 >> N2 >> N3 >> N4;
    vector<bool> b(10, false);
    b[N1] = true;
    b[N2] = true;
    b[N3] = true;
    b[N4] = true;

    if (b[1] && b[9] && b[7] && b[4]) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
