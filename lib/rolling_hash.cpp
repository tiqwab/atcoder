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

class RollingHash {
    const int base = 9973;
    const int mod = 1000000007;
    string S;
    vector<ll> hash, power;

    public:
        RollingHash(const string &cs) {
            S = cs;
            int n = (int) S.size();
            hash.assign(n + 1, 0);
            power.assign(n + 1, 1);
            for (int i = 0; i < n; i++) {
                hash[i + 1] = (hash[i] * base + S[i]) % mod;
                power[i + 1] = power[i] * base % mod;
            }
        }

        // Get hash of S[left:right] (left: inclusive, right: exclusive)
        // if S = aabaaa, rh.get(0, 2) calculates hash of 'aa' {S[0], S[1]}.
        inline ll get(int l, int r) const {
            ll res = hash[r] - hash[l] * power[r - l] % mod;
            if (res < 0) res += mod;
            return res;
        }
};

/*
 * ref. http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B&lang=jp
 * ref. http://drken1215.hatenablog.com/entry/2019/03/19/015700
 */
int main(void) {
    string T, P;
    cin >> T >> P;

    int lenT = (int) T.size();
    int lenP = (int) P.size();

    if (lenT < lenP) {
        return 0;
    }

    RollingHash rhT(T);
    RollingHash rhP(P);

    ll hash = rhP.get(0, lenP);

    for (int i = 0; i < lenT - lenP + 1; i++) {
        if (hash == rhT.get(i, i + lenP)) {
            if (T.substr(i, lenP) == P) {
                cout << i << "\n"; // avoid endl (it flush buffers each time) when there are many outputs
            }
        }
    }

    return 0;
}
