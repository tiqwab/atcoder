#include <algorithm>
#include <bitset>
#include <iostream>
#include <vector>

#include <string.h>

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

const int MAX_S = 10;

ll solve(const int orig_bits, const int slen, const char *s) {
    ll acc = 0LL;
    ll current = 0LL;
    int bits = orig_bits;
    const char *p = s;
    while (bits > 0) {
        current = current * 10 + ((*p) - '0');
        if (bits & 1) {
            acc += current;
            current = 0LL;
        }
        p++;
        bits >>= 1;
    }
    if (((intptr_t) p) - ((intptr_t) s) < slen) {
        while (*p != 0) {
            current = current * 10 + ((*p) - '0');
            p++;
        }
        acc += current;
    }

    // cout << bitset<8>(orig_bits) << "," << acc << endl;
    return acc;
}

int main(void) {
    char S[MAX_S + 1];
    cin >> S;
    int len = strlen(S);

    ll acc = 0;
    for (int bits = 0; bits < 1 << (len - 1); bits++) {
        acc += solve(bits, len, S);
    }

    cout << acc << endl;
    
    return 0;
}
