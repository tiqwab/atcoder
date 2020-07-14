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
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;

        // {K, L, R}
        vector<tuple<int, int, int>> alls;
        vector<tuple<int, int, int>> ls;
        vector<tuple<int, int, int>> rs;

        for (int i = 0; i < N; i++) {
            int K, L, R;
            cin >> K >> L >> R;
            alls.push_back(make_tuple(K, L, R));
            if (L >= R) {
                ls.push_back(make_tuple(K, L, R));
            } else {
                rs.push_back(make_tuple(N - K, R, L));
            }
        }
        sort(alls.rbegin(), alls.rend());
        sort(ls.rbegin(), ls.rend());
        sort(rs.rbegin(), rs.rend());

        auto f = [](const vector<tuple<int, int, int>> &camels) {
            const int N = (int) camels.size();
            ll acc = 0;

            // {diff hapiness, bigger hapiness, smaller hapiness}
            priority_queue<tuple<int, int, int>> que;
            int ind = 0;
            for (int pos = N; pos > 0; pos--) {
                while (ind < N) {
                    int K, L, R;
                    tie(K, L, R) = camels[ind];
                    if (K >= pos) {
                        que.push(make_tuple(L - R, L, R));
                        ind++;
                    } else {
                        break;
                    }
                }

                if (que.empty()) {
                    continue;
                }

                {
                    int a, b, c;
                    tie(a, b, c) = que.top();
                    acc += b;
                    que.pop();
                }
            }

            while (ind < (int) camels.size()) {
                int K, L, R;
                tie(K, L, R) = camels[ind];
                que.push(make_tuple(L - R, L, R));
                ind++;
            }

            while (!que.empty()) {
                int a, b, c;
                tie(a, b, c) = que.top();
                acc += c;
                que.pop();
            }

            return acc;
        };

        ll ans = f(ls);
        // printf("f(ls): %lld\n", f(ls));
        ans += f(rs);
        // printf("f(rs): %lld\n", f(rs));
        cout << ans << endl;

    }

    return 0;
}
