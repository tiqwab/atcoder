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

int main(void) {
    ll n;
    cin >> n;

    string ans = "";

    while (n != 0) {
        n--;
        int a = n % 26;
        ans.push_back('a' + a);
        n /= 26;
    }
    reverse(ans.begin(), ans.end());

    cout << ans << endl;

    return 0;
}
