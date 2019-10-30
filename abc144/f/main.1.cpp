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

// ref. https://atcoder.jp/contests/abc144/submissions/8133816

const int MAX_N = 600;

int n, m;
vector<int> edges[MAX_N];
double dp[MAX_N];
double answer = MAX_N + 1;

void solve(int block) {
    dp[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--) {
        double sum = 0.0;
        double max_cost = 0.0;
        double num = (double) edges[i].size();
        for (auto to : edges[i]) {
            sum += dp[to - 1];
            chmax(max_cost, dp[to - 1]);
        }
        if (i == block && num >= 2) {
            sum -= max_cost;
            num--;
        }
        dp[i] = 1.0 + sum / num;
    }

    chmin(answer, dp[0]);
}

int main(void) {
    cin >> n >> m;

    for (int i = 0; i < m ; i++) {
        int s, t;
        cin >> s >> t;
        edges[s-1].push_back(t);
    }

    for (int i = 0; i < n-1; i++) {
        solve(i);
    }

    printf("%3.7f\n", answer);

    return 0;
}
