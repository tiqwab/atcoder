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

const int INF = INT_MAX / 2;

vector<int> prices;
vector<vector<int>> unds;

int solve(const int N, const int M, const int X) {
    int cand = INF;
    for (int bits = 0; bits < (1 << N); bits++) {
        int sum_price = 0;
        vector<int> sum_unds(M, 0);
        for (int i = 0; i < N; i++) {
            if (bits & (1 << i)) {
                sum_price += prices[i];
                for (int j = 0; j < M; j++) {
                    sum_unds[j] += unds[i][j];
                }
            }
        }
        bool ok = true;
        for (int i = 0; i < M; i++) {
            if (sum_unds[i] < X) {
                ok = false;
            }
        }
        if (ok) {
            chmin(cand, sum_price);
        }
    }

    return cand;
}

int main(void) {
    int N, M, X;
    cin >> N >> M >> X;

    prices.resize(N, 0);
    unds.resize(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++) {
        cin >> prices[i];
        for (int j = 0; j < M; j++) {
            cin >> unds[i][j];
        }
    }

    int ans = solve(N, M, X);
    if (ans == INF) {
        ans = -1;
    }

    cout << ans << endl;

    return 0;
}
