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

const int INF = INT_MAX / 4;
const int MAX_LEN = 1000;

int calc_min_mp(const int target, const vector<int> &bs) {
    int acc = 0;
    for (auto &b : bs) {
        acc += b;
    }
    return abs(target - acc) + ((int) bs.size() - 1) * 10;
}

string show_vec(const vector<int> &bs) {
    string s;
    s += "{";
    for (auto &b : bs) {
        s += to_string(b) + ", ";
    }
    s += "}";
    return s;
}

int pow(const int base, const int x) {
    int ans = 1;
    for (int i = 0; i < x; i++) {
        ans *= base;
    }
    return ans;
}

int main(void) {
    int N, A, B, C;
    cin >> N >> A >> B >> C;

    vector<int> bs(N);
    for (int i = 0; i < N; i++) {
        cin >> bs[i];
    }

    int ans = INF;
    int max_i = pow(4, N);
    for (int i = 0; i < max_i; i++) {
        int x = i;
        vector<int> bs1, bs2, bs3;
        for (int j = 0; j < N; j++) {
            int y = x % 4;
            if (y == 0) {
                bs1.push_back(bs[j]);
            } else if (y == 1) {
                bs2.push_back(bs[j]);
            } else if (y == 2) {
                bs3.push_back(bs[j]);
            }
            x /= 4;
        }

        int cost_a = (bs1.size() > 0) ? calc_min_mp(A, bs1) : INF;
        int cost_b = (bs2.size() > 0) ? calc_min_mp(B, bs2) : INF;
        int cost_c = (bs3.size() > 0) ? calc_min_mp(C, bs3) : INF;
        // printf("---\n");
        // cout << "[A] vec: " + show_vec(bs1) + ", cost: " << cost_a << endl;
        // cout << "[B] vec: " + show_vec(bs2) + ", cost: " << cost_b << endl;
        // cout << "[C] vec: " + show_vec(bs3) + ", cost: " << cost_c << endl;
        // cout << "sum: " << cost_a + cost_b + cost_c << endl;
        chmin(ans, cost_a + cost_b + cost_c);
    }

    cout << ans << endl;

    return 0;
}
