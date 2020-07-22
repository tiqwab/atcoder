#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

#include <limits.h>

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

bool is_palindrome(const int x) {
    string s = to_string(x);
    string t = s;
    reverse(t.begin(), t.end());
    return s == t;
}

int main(void) {
    int A, B;
    cin >> A >> B;

    int ans = 0;
    for (int i = A; i <= B; i++) {
        if (is_palindrome(i)) {
            ans++;
        }
    }
    cout << ans << endl;
    
    return 0;
}
