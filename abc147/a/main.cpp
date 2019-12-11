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
    int A1, A2, A3;
    cin >> A1 >> A2 >> A3;

    if (A1 + A2 + A3 >= 22) {
        cout << "bust" << endl;
    } else {
        cout << "win" << endl;
    }
    
    return 0;
}
