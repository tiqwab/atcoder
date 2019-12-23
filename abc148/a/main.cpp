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
    bool ans[4] = {true, true, true, true};
    ans[A] = false;
    ans[B] = false;
    for (int i = 1; i < 4; i++) {
        if (ans[i]) {
            cout << i << endl;
        }
    }

    return 0;
}
