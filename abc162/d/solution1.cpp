#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <queue>
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

vector<int> rs;
vector<int> gs;
vector<int> bs;

ll calc(const vector<int> &as, const vector<int> &bs, const vector<int> &cs) {
    ll ans = 0;
    for (auto &r : as) {
        auto p_g = upper_bound(bs.begin(), bs.end(), r);
        while (p_g != bs.end()) {
            const int g = *p_g;
            auto p_b = upper_bound(cs.begin(), cs.end(), g);
            ans += cs.end() - p_b;
            // if (p_b != cs.end()) {
            //     printf("fiast: %d, second: %d, += %ld\n", r, g, cs.end() - p_b);
            // }

            p_b = lower_bound(cs.begin(), cs.end(), g + (g - r));
            if (p_b != cs.end() && *p_b - g == g - r) {
                // printf("but ignore it\n");
                ans--;
            }
            p_g++;
        }
    }
    return ans;
}

ll solve(const int N) {
    ll ans = 0;

    ans += calc(rs, gs, bs);
    ans += calc(rs, bs, gs);
    ans += calc(gs, rs, bs);
    ans += calc(gs, bs, rs);
    ans += calc(bs, rs, gs);
    ans += calc(bs, gs, rs);

    return ans;
}

int main(void) {
    int N;
    cin >> N;
    string S;
    cin >> S;

    for (int i = 0; i < N; i++) {
        char c = S[i];
        if (c == 'R') {
            rs.push_back(i);
        } else if (c == 'G') {
            gs.push_back(i);
        } else {
            bs.push_back(i);
        }
    }

    cout << solve(N) << endl;

    return 0;
}
