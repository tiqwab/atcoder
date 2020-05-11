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

int ans = INF;

// return INF if the condition is not satisfied
int calc(const vector<int> &books, const int M, const int X) {
    int acc_price = 0;
    vector<int> acc_unds(M, 0);
    for (auto b : books) {
        acc_price += prices[b];
        for (int i = 0; i < M; i++) {
            acc_unds[i] += unds[b][i];
        }
    }

    bool ok = true;
    for (int i = 0; i < M; i++) {
        if (acc_unds[i] < X) {
            ok = false;
        }
    }

    if (ok) {
        return acc_price;
    } else {
        return INF;
    }
}

void solve(int cur, vector<int> &books, const int N, const int M, const int X) {
    if (cur == N) {
        chmin(ans, calc(books, M, X));
        return;
    }

    // not use book
    solve(cur + 1, books, N, M, X);

    // use book
    books.push_back(cur);
    solve(cur + 1, books, N, M, X);
    books.pop_back();
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

    {
        vector<int> books;
        solve(0, books, N, M, X);
    }

    if (ans == INF) {
        ans = -1;
    }

    cout << ans << endl;

    return 0;
}
