#include <algorithm>
#include <iostream>
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

int solve(const vector<pair<int, int>> &sc, const int N, const int M) {
    for (int cand = 0; cand < 1000; cand++) {
        int x = cand;
        vector<int> digits;
        digits.push_back(x % 10);
        x /= 10;
        while (x) {
            digits.push_back(x % 10);
            x /= 10;
        }
        reverse(digits.begin(), digits.end());

        if ((int) digits.size() != N) {
            continue;
        }

        bool ok = true;
        for (auto &p : sc) {
            if (digits[p.first] != p.second) {
                ok = false;
                break;
            }
        }

        if (ok) {
            return cand;
        }
    }
    return -1;
}

// based on solution 1 in pdf.
// ref. https://img.atcoder.jp/abc157/editorial.pdf
int main(void) {
    int N, M;
    cin >> N >> M;
    
    vector<pair<int, int>> sc(M);
    for (int i = 0; i < M; i++) {
        int s, c;
        cin >> s >> c;
        s--;
        sc[i] = {s, c};
    }

    cout << solve(sc, N, M) << endl;
    
    return 0;
}
