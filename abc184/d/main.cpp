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

double dp[105][105][105];
bool visited[105][105][105];

int main(void) {
    int A, B, C;
    cin >> A >> B >> C;

    dp[A][B][C] = 1;

    queue<tuple<int, int, int>> q;
    q.push(make_tuple(A, B, C));
    visited[A][B][C] = true;

    while (!q.empty()) {
        tuple<int, int, int> elem = q.front();
        q.pop();

        int a, b, c;
        tie(a, b, c) = elem;

        double prob = dp[a][b][c];
        dp[a + 1][b][c] += prob * double(a) / double(a + b + c);
        if (a + 1 < 100 && !visited[a + 1][b][c]) {
            q.push(make_tuple(a + 1, b, c));
            visited[a + 1][b][c] = true;
        }
        dp[a][b + 1][c] += prob * double(b) / double(a + b + c);
        if (b + 1 < 100 && !visited[a][b + 1][c]) {
            q.push(make_tuple(a, b + 1, c));
            visited[a][b + 1][c] = true;
        }
        dp[a][b][c + 1] += prob * double(c) / double(a + b + c);
        if (c + 1 < 100 && !visited[a][b][c + 1]) {
            q.push(make_tuple(a, b, c + 1));
            visited[a][b][c + 1] = true;
        }
    }

    double ans = 0;
    for (int a = 0; a <= 100; a++) {
        for (int b = 0; b <= 100; b++) {
            for (int c = 0; c <= 100; c++) {
                if (a == 100 || b == 100 || c == 100) {
                    ans += dp[a][b][c] * ((a + b + c) - (A + B + C));
                }
            }
        }
    }

    printf("%.7f\n", ans);
    return 0;
}
