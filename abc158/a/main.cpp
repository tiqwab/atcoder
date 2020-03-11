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

    bool has_a = false;
    bool has_b = false;

    for (int i = 0; i < (int) S.size(); i++) {
        if (S[i] == 'A') has_a = true;
        else if (S[i] == 'B') has_b = true;
    }

    if (has_a && has_b) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
