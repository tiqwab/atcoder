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

int main(void) {
    string S;
    cin >> S;

    const int slen = (int) S.size();

    string cand1, cand2;
    for (int i = 0; i < slen; i++) {
        cand1 += (i % 2 == 0) ? "1" : "0";
        cand2 += (i % 2 == 0) ? "0" : "1";
    }

    int diff1 = 0;
    for (int i = 0; i < slen; i++) {
        if (cand1[i] != S[i]) {
            diff1++;
        }
    }

    int diff2 = 0;
    for (int i = 0; i < slen; i++) {
        if (cand2[i] != S[i]) {
            diff2++;
        }
    }

    cout << min(diff1, diff2) << endl;

    return 0;
}
