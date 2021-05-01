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
    int N;
    cin >> N;

    string S;
    cin >> S;
    string s = S.substr(0, N);
    string t = S.substr(N, N);

    int Q;
    cin >> Q;

    for (int i = 0; i < Q; i++) {
        int T, A, B;
        cin >> T >> A >> B;

        if (T == 1) {
            A--;
            B--;
            if (A < N) {
                if (B < N) {
                    swap(s[A], s[B]);
                } else {
                    swap(s[A], t[B - N]);
                }
            } else {
                swap(t[A - N], t[B - N]);
            }
        } else {
            swap(s, t);
        }
    }

    cout << s << t << endl;

    return 0;
}
