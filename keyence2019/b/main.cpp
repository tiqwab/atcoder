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

bool solve(const string &S) {
    int slen = (int) S.size();
    for (int i = 0; i <= slen; i++) {
        for (int j = i; j <= slen; j++) {
            string s = S.substr(0, i);
            if (j != slen) {
                s += S.substr(j + 1, slen - j - 1);
            }
            // cout << s << endl;
            if (s == "keyence") {
                return true;
            }
        }
    }
    return false;
}

int main(void) {
    string S;
    cin >> S;

    if (solve(S)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}
