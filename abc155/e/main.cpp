#include <algorithm>
#include <iostream>
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

const int INF = INT_MAX / 2;

vector<int> dp1;
vector<int> dp2;

int solve(int pos, const int orig_carry, const string S, const int slen) {
    if (orig_carry) {
        if (dp1[pos] != INF) {
            return dp1[pos];
        }
    } else {
        if (dp2[pos] != INF) {
            return dp2[pos];
        }
    }

    int acc = 0;

    if (pos < slen) {
        int d = S[pos] - '0';
        int carry;
        d += orig_carry;
        if (d == 0) {
            carry = 0;
            acc += solve(pos + 1, carry, S, slen);
        } else if (d < 5) {
            acc += d;
            carry = 0;
            acc += solve(pos + 1, carry, S, slen);
        } else if (d == 5) {
            acc += d;
            acc += min(solve(pos + 1, 0, S, slen), solve(pos + 1, 1, S, slen));
        } else {
            acc += 10 - d;
            carry = 1;
            acc += solve(pos + 1, carry, S, slen);
        }
    } else {
        acc += orig_carry;
    }

    if (orig_carry) {
        dp1[pos] = acc;
    } else {
        dp2[pos] = acc;
    }

    return acc;
}

int main(void) {
    string S;
    cin >> S;
    int slen = (int) S.size();

    reverse(S.begin(), S.end());

    dp1.resize(slen + 1, INF);
    dp2.resize(slen + 1, INF);

    cout << solve(0, 0, S, slen) << endl;

    return 0;
}
