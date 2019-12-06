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
    ll T1, T2, A1, A2, B1, B2;
    cin >> T1 >> T2 >> A1 >> A2 >> B1 >> B2;

    A1 *= T1;
    A2 *= T2;
    B1 *= T1;
    B2 *= T2;

    if (B1 < A1) {
        swap(A1, B1);
        swap(A2, B2);
    }

    if (A1 + A2 < B1 + B2) {
        cout << "0" << endl;
    } else if (A1 + A2 == B1 + B2) {
        cout << "infinity" << endl;
    } else {
        ll a = (A1 + A2) - (B1 + B2);
        ll b = (B1 - A1) / a;
        if (((B1 - A1) % a) == 0) {
            cout << b * 2 << endl;
        } else {
            cout << b * 2 + 1 << endl;
        }
    }
    
    return 0;
}
