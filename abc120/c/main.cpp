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

    int zero_count = 0;
    int one_count = 0;
    for (int i = 0; i < (int) S.size(); i++) {
        if (S[i] == '0') {
            zero_count++;
        } else {
            one_count++;
        }
    }

    cout << 2 * min(zero_count, one_count) << endl;

    return 0;
}
