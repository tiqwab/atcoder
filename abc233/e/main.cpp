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

vector<ll> ss;

int main(void) {
    string S;
    cin >> S;
    int slen = (int) S.size();

    ss.resize(slen + 1, 0);
    for (int i = 1; i < slen + 1; i++) {
        ss[i] = ss[i - 1] + (S[i - 1] - '0');
    }
#ifdef DEBUG
    printf("ss: \n");
    for (auto s : ss) {
        printf("  %lld\n", s);
    }
#endif

    ll carry = 0;
    vector<ll> ans;
    for (int i = 0; i < slen; i++) {
        ll d = ss[slen - i] + carry;
        ans.push_back(d % 10);
        carry = d / 10;
    }
#ifdef DEBUG
    printf("ans after first step: \n");
    for (auto a : ans) {
        printf("  %lld\n", a);
    }
#endif

    while (carry > 0) {
        ans.push_back(carry % 10);
        carry /= 10;
    }

    reverse(ans.begin(), ans.end());
    for (auto a : ans) {
        printf("%lld", a);
    }
    printf("\n");

    return 0;
}
