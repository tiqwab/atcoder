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

vector<int> as;
vector<int> dp;
vector<vector<vector<int>>> seqs;

int main(void) {
    int N;
    cin >> N;

    as.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> as[i];
    }

    dp.resize(200, 0);
    seqs.resize(200);
    for (int i = 0 ; i < N; i++) {
        int a = as[i] % 200;
        vector<int> tmp_dp = dp;
        vector<vector<vector<int>>> tmp_seqs = seqs;

        for (int j = 0; j < 200; j++) {
            if (dp[j]) {
                // tmp_dp[(j + a) % 200] += dp[j];
                tmp_dp[(j + a) % 200] = min(2, tmp_dp[(j + a) % 200] + dp[j]);

                // for (auto ss : seqs[j]) {
                //     ss.push_back(i);
                //     tmp_seqs[(j + a) % 200].push_back(ss);
                // }
                if ((int) tmp_seqs[(j + a) % 200].size() < 2) {
                    for (int k = 0; k < min(2, (int) seqs[j].size()); k++) {
                        auto v = seqs[j][k];
                        v.push_back(i);
                        tmp_seqs[(j + a) % 200].push_back(v);
                    }
                }
            }
        }

        tmp_dp[a] += 1;
        swap(dp, tmp_dp);

        tmp_seqs[a].push_back({i});
        swap(seqs, tmp_seqs);
    }

#ifdef DEBUG
    for (int i = 0; i < 200; i++) {
        printf("dp[%d]: %d\n", i, dp[i]);
        for (auto ss : seqs[i]) {
            printf("  ");
            for (auto s : ss) {
                printf("%d ", s);
            }
            printf("\n");
        }
    }
    cout << endl;
#endif

    for (int i = 0; i < 200; i++) {
        if (dp[i] > 1) {
            cout << "Yes" << endl;

            vector<int> as = seqs[i][0];
            printf("%d ", (int) as.size());
            for (int j = 0; j < (int) as.size(); j++) {
                if (j != (int) as.size() - 1) {
                    cout << as[j] + 1 << " ";
                } else {
                    cout << as[j] + 1 << "\n";
                }
            }

            vector<int> bs = seqs[i][1];
            printf("%d ", (int) bs.size());
            for (int j = 0; j < (int) bs.size(); j++) {
                if (j != (int) bs.size() - 1) {
                    cout << bs[j] + 1 << " ";
                } else {
                    cout << bs[j] + 1 << "\n";
                }
            }
            return 0;
        }
    }

    cout << "No" << endl;
    return 0;
}
