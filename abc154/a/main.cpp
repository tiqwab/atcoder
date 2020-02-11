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
    string S, T;
    cin >> S >> T;
    int A, B;
    cin >> A >> B;
    string U;
    cin >> U;
    if (S == U) {
        A--;
    } else {
        B--;
    }

    cout << A << " " << B << endl;
    return 0;
}
