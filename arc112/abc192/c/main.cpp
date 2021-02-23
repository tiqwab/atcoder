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

string i_to_s(int x) {
    string s;
    while (x > 0) {
        s += '0' + (x % 10);
        x /= 10;
    }
    reverse(s.begin(), s.end());
    return s;
}

int s_to_i(const string s) {
    int x = 0;
    for (auto c : s) {
        x = x * 10 + c - '0';
    }
    return x;
}

int main(void) {
    int N, K;
    cin >> N >> K;

    int cur = N;

    for (int i = 0; i < K; i++) {
        string s = i_to_s(cur);
        sort(s.rbegin(), s.rend());
        int one = s_to_i(s);
        reverse(s.begin(), s.end());
        int two = s_to_i(s);
        cur = one - two;
    }

    printf("%d\n", cur);
    
    return 0;
}
