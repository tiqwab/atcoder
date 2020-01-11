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
    string S;
    cin >> S;

    for (int i = 1; i < (int) S.size(); i++) {
        if (S[i - 1] == S[i]) {
            cout << "Bad" << endl;
            return 0;
        }
    }

    cout << "Good" << endl;

    return 0;
}
