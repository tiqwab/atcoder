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

// [start, end]
bool is_palindrome(const int start, const int end, const string &S) {
    const int len = end - start + 1;
    for (int i = 0; i < len; i++) {
        if (S[start + i] != S[end - i]) {
            return false;
        }
    }
    return true;
}

int main(void) {
    string S;
    cin >> S;
    const int slen = (int) S.size();

    if (is_palindrome(0, (slen - 3) / 2, S) &&
            is_palindrome((slen + 1) / 2, slen - 1, S) &&
            is_palindrome(0, slen - 1, S)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
