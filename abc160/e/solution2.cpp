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

// {value, color}
// 'r' = red, 'g' = green, '-': nothing
vector<pair<ll, char>> all;

ll solve(const ll X, const ll Y, const ll A, const ll B, const ll C,
        const vector<ll> ps, const vector<ll> qs) {
    ll ans = 0;
    ll cnt_p = 0;
    ll cnt_q = 0;

    ll cnt_pmy = 0;
    ll cnt_qmy = 0;

    auto calc_cnt_p = [&]() {
        return cnt_p + cnt_pmy;
    };

    auto calc_cnt_q = [&]() {
        return cnt_q + cnt_qmy;
    };

    for (int i = (int) all.size() - 1; i >= 0; i--) {
        if (calc_cnt_p() == X && calc_cnt_q() == Y) break;

        ll value = all[i].first;
        char color = all[i].second;

        if (color == 'r') {
            if (calc_cnt_p() == X) continue;
            ans += value;
            cnt_pmy++;
            // printf("value: %lld, color: %c, cnt for p: %lld, cnt for q: %lld, ans: %lld\n",
            //         value, color, cnt_p + cnt_pmy, cnt_q + cnt_qmy, ans);
            continue;
        }

        if (color == 'g') {
            if (calc_cnt_q() == Y) continue;
            ans += value;
            cnt_qmy++;
            // printf("value: %lld, color: %c, cnt for p: %lld, cnt for q: %lld, ans: %lld\n",
            //         value, color, cnt_p + cnt_pmy, cnt_q + cnt_qmy, ans);
            continue;
        }

        // when no color
        if (calc_cnt_p() == X) {
            // color as green
            ans += value;
            cnt_q++;
            // printf("value: %lld, color: %c, cnt for p: %lld, cnt for q: %lld, ans: %lld\n",
            //         value, color, cnt_p + cnt_pmy, cnt_q + cnt_qmy, ans);
        } else if (calc_cnt_q() == Y) {
            // color as red
            ans += value;
            cnt_p++;
            // printf("value: %lld, color: %c, cnt for p: %lld, cnt for q: %lld, ans: %lld\n",
            //         value, color, cnt_p + cnt_pmy, cnt_q + cnt_qmy, ans);
        } else {
            ll expect_p = value - ps[cnt_p];
            ll expect_q = value - qs[cnt_q];
            // printf("%lld, %lld\n", X - cnt_p, Y - cnt_q);
            // printf("expect_p: %lld, expec_q: %lld\n", expect_p, expect_q);
            if (expect_p > expect_q) {
                // color as red
                ans += value;
                cnt_p++;
                // printf("value: %lld, color: %c, cnt for p: %lld, cnt for q: %lld, ans: %lld\n",
                //         value, color, cnt_p + cnt_pmy, cnt_q + cnt_qmy, ans);
            } else {
                // color as green
                ans += value;
                cnt_q++;
                // printf("value: %lld, color: %c, cnt for p: %lld, cnt for q: %lld, ans: %lld\n",
                //         value, color, cnt_p + cnt_pmy, cnt_q + cnt_qmy, ans);
            }
        }
    }

    return ans;
}

int main(void) {
    ll X, Y, A, B, C;
    cin >> X >> Y >> A >> B >> C;

    vector<ll> ps;
    vector<ll> qs;
    vector<ll> rs;

    ps.resize(A);
    for (int i = 0; i < A; i++) {
        cin >> ps[i];
        all.push_back({ps[i], 'r'});
    }

    qs.resize(B);
    for (int i = 0; i < B; i++) {
        cin >> qs[i];
        all.push_back({qs[i], 'g'});
    }

    rs.resize(C);
    for (int i = 0; i < C; i++) {
        cin >> rs[i];
        all.push_back({rs[i], '-'});
    }

    sort(ps.begin(), ps.end());
    sort(qs.begin(), qs.end());
    sort(rs.begin(), rs.end());
    sort(all.begin(), all.end());

    vector<ll> ps2;
    {
        reverse(ps.begin(), ps.end());
        int i;
        for (i = 0; i < min(X, A); i++) {
            ps2.push_back(ps[i]);
        }
        while (i < X) {
            ps2.push_back(0);
            i++;
        }
        reverse(ps.begin(), ps.end());
    }
    reverse(ps2.begin(), ps2.end());

    vector<ll> qs2;
    {
        reverse(qs.begin(), qs.end());
        int i;
        for (i = 0; i < min(Y, B); i++) {
            qs2.push_back(qs[i]);
        }
        while (i < Y) {
            qs2.push_back(0);
            i++;
        }
        reverse(qs.begin(), qs.end());
    }
    reverse(qs2.begin(), qs2.end());

    cout << solve(X, Y, A, B, C, ps2, qs2) << endl;

    return 0;
}
