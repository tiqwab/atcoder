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

bool can_be_mm(const char a, const char b) {
    int x = a - '0';
    int y = b - '0';

    if (x >= 2) {
        return false;
    } else if (x == 1) {
        return y <= 2;
    } else {
        return y != 0;
    }
}

int main(void) {
    string S;
    cin >> S;

    bool is_yymm = false, is_mmyy = false;

    if (can_be_mm(S[2], S[3])) {
        is_yymm = true;
    }
    if (can_be_mm(S[0], S[1])) {
        is_mmyy = true;
    }

    if (is_yymm && is_mmyy) {
        cout << "AMBIGUOUS" << endl;
    } else if (is_yymm) {
        cout << "YYMM" << endl;
    } else if (is_mmyy) {
        cout << "MMYY" << endl;
    } else {
        cout << "NA" << endl;
    }

    return 0;
}
