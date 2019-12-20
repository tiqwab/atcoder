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

void solve(const int small, const int big) {
    if ((big - small) % 2 == 0){
        cout <<  ((big - small) / 2 + small) << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
}

int main(void) {
    int A, B;
    cin >> A >> B;

    if (A < B) {
        solve(A, B);
    } else {
        solve(B, A);
    }
    
    return 0;
}
