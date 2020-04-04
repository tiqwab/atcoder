#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <queue>
#include <set>
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

int str_to_i(string S) {
    int acc = 0;
    for (int i = 0; i < (int) S.size(); i++) {
        int d = S[i] - '0';
        acc = acc * 10 + d;
    }
    return acc;
}

int main(void) {
    string S;
    cin >> S;

    int year = str_to_i(S.substr(0, 4));
    int month = str_to_i(S.substr(5, 2));
    int day = str_to_i(S.substr(8, 2));

    if (month <= 4) {
        cout << "Heisei" << endl;
    } else {
        cout << "TBD" << endl;
    }

    return 0;
}
